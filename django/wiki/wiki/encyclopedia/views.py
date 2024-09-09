from django.shortcuts import render
from django.shortcuts import render, redirect

from django.urls import reverse
import markdown2
from encyclopedia.forms import EntryForm, ModifyEntry

from . import util
import random as randomize

valid_entries =  util.list_entries()

_DUPLICATE = "📄 The article you're trying to create already exists."
_INVALID_SEARCH = " ❌ We couldn't find any relevant results for your search."
_DOES_NOT_EXIST = " ❌ The page you requested could not be found."



def index(request):
    return render(request, "encyclopedia/index.html", {
        "entries": util.list_entries()
    })

def entry_page (request, title):
    entry_title = util.get_entry(title)
    if entry_title == None:
        return render (request, "encyclopedia/invalid.html", {
            "error_msg": _DOES_NOT_EXIST
    })
    else:
        return render(request, "encyclopedia/entry_page.html", {
            "page": markdown2.markdown (entry_title),
            "title": title
    })
        
def random_page (request):
            random_entry = randomize.choice(valid_entries)
            return redirect(reverse('entry_page', args=[random_entry]))
        
def search_entry (request):
    has_relevant = False
    if request.method == "GET":
        keyword = request.GET['q']
        valid_results = []
        valid_entries = util.list_entries()
            
        for result in valid_entries:
            if keyword.lower().strip() == result.lower().strip():
                return redirect(reverse('entry_page', args=[result]))
            else:
                if keyword.lower().strip() in result.lower().strip() :
                    valid_results.append(result)
        if len(valid_results) > 0 :
                has_relevant = True
        return render(request, "encyclopedia/search_results.html", {
            "is_found": False,
            "has_relevant": has_relevant,
            "results": valid_results,
            "title": keyword,
            "error_msg": _INVALID_SEARCH
     })

def new_page (request):
                
    if request.method == "POST":
        data = EntryForm(request.POST)
        title, content = request.POST['title'].strip(), request.POST['content'].strip()
        
        if data.is_valid():
            if util.get_entry(title) != None:
                return render (request, "encyclopedia/invalid.html", {
                    "error_msg": _DUPLICATE
            })
            else: 
                content = "# " + title + " \n\n" + content
                util.save_entry(title, content) 
                return render(request, "encyclopedia/entry_page.html", {
                    "page": markdown2.markdown (util.get_entry(title)),
                    "title": title
            })
                
    return render(request, "encyclopedia/new_page.html",{
    "form": EntryForm()
    })
                
                    
            
def modify_page (request, title):
            
    initial_content = {
        'modified_content' : util.get_entry(title)
    }
    
    if request.method == "GET":
        return render(request, "encyclopedia/modify_page.html", {
            "title": title,
            "form": ModifyEntry(initial=initial_content),
            "page": markdown2.markdown (util.get_entry(title)),
    })
        
    if request.method == "POST":
        form = ModifyEntry(request.POST)
        if form.is_valid():   
            updated = form.cleaned_data['modified_content']
            if ("# " + title) not in updated:
                updated = "# " + title + " \n\n" + updated
            util.save_entry(title, updated)
        return redirect(reverse('entry_page', args=[title]))
        
