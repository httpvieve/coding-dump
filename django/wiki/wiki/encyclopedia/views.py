from django.shortcuts import render
from django.shortcuts import render, redirect
from django import forms
from django.urls import reverse
import markdown2

from . import util
import random as randomize

valid_entries =  util.list_entries()

_DUPLICATE = 1
_INVALID_SEARCH = 2
_DOES_NOT_EXIST = 3


def define_error (error_type):
    if error_type == _INVALID_SEARCH:
        return " ❌ We couldn't find any results for your search."
    if error_type == _DUPLICATE:
        return "📄 The article you're trying to create already exists."
    if error_type == _DOES_NOT_EXIST:
                return " ❌ The page you requested could not be found."
          
# class EntryForm (forms.Form):
#     class Meta:
#         model = Entry
#         fields = ['title', 'content']          

class ModifyEntry (forms.Form):
    modified_content = forms.CharField(widget=forms.Textarea)

class EntryForm (forms.Form):
        
    title = forms.CharField (label="Title: ")
    content = forms.CharField(label="Content:", widget=forms.Textarea)
    

def index(request):
    return render(request, "encyclopedia/index.html", {
        "entries": util.list_entries()
    })

def entry_page (request, title):
    entry_title = util.get_entry(title)
    if entry_title == None:
        return render (request, "encyclopedia/invalid.html", 
                {"error_msg": define_error(_DOES_NOT_EXIST)})
    else:
        return render(request, "encyclopedia/entry_page.html", {
            "page": markdown2.markdown (entry_title),
            "title": title
    })
        
def random_page (request):
            random_entry = randomize.choice(valid_entries)
            return redirect(reverse('entry_page', args=[random_entry]))
        
def search_entry (request):
    if request.method == "GET":
        keyword = request.GET['q']
        valid_results = []
        valid_entries = util.list_entries()
        for result in valid_entries:
            if keyword.lower() in result.lower():
                valid_results.append(result)

        return render(request, "encyclopedia/search_results.html", {
            "results": valid_results,
            "title": keyword,
            "error_msg": define_error(_INVALID_SEARCH)
     })

def new_page (request):
                
    if request.method == "POST":
        data = EntryForm(request.POST)
        title, content = request.POST['title'].strip(), request.POST['content'].strip()
        
        if data.is_valid():
            if util.get_entry(title) != None:
                return render (request, "encyclopedia/invalid.html", 
                {"error_msg": define_error(_DUPLICATE)})
            else: 
                content = "# " + title + " \n\n" + content
                util.save_entry(title, content) # add entry
                # return redirect(reverse('index'))
                return render(request, "encyclopedia/entry_page.html", {
                "page": markdown2.markdown (util.get_entry(title)),
                "title": title
        })
    return render(request, "encyclopedia/new_page.html",{
    "form": EntryForm()
    })
                
                    
            
def modify_page (request, title):
            
    initial_data = {
        'modified_content' : util.get_entry(title)
    }
    
    if request.method == "GET":
        return render(request, "encyclopedia/modify_page.html", {
                "title": title,
                "form": ModifyEntry(initial=initial_data),
                "page": markdown2.markdown (util.get_entry(title)),
                })
        
    if request.method == "POST":
        updated = request.POST['modified_content'].strip()
        # form = ModifyEntry(initial=initial_data)
        # if form.is_valid():
        # updated = form.cleaned_data['modified_content']
        util.save_entry(title, updated)
        return redirect(reverse('entry_page', args=[title]))
        
