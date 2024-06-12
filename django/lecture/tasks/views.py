from django.http import HttpResponseRedirect
from django.shortcuts import render
from django.urls import reverse
from django import forms

# Create your views here.
# tasks = [] -> global, so only one data for all sessions 

class addtask_form (forms.Form):
        task = forms.CharField (label="New task ")
        # priority = forms.IntegerField(label="Priority", min_value = 1, max_value = 5)
# class deletetask_form (forms.Form):
#         choices = {}
#         choice = forms.ChoiceField(widget=forms.RadioSelect, choices = tasks)       
def index(request):
        if "tasks" not in request.session:
                request.session["tasks"] = [] #initialize for every session
                
        return render(request, "tasks/index.html", {
                "tasks" : request.session["tasks"] #array
        })
        
def add (request):
        if request.method == "POST":
                form = addtask_form(request.POST)
                if form.is_valid():
                        new_task = form.cleaned_data["task"]
                        request.session["tasks"] += [new_task]
                        return HttpResponseRedirect(reverse("tasks:index")) # return after submit
                else:
                        return render(request, "tasks.add.html", {
                                "form": form
                        })                        
        return render(request, "tasks/add.html", {
                "form": addtask_form()
        })

# def delete_task (request):
#         choice = deletetask_form(request.GET)
#         request.session["tasks"].remove([choice])
#         return HttpResponseRedirect(reverse("tasks:index")) # return after submit
        