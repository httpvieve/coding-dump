from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.

#def index (request):
#         return HttpResponse("Welcome!")

def index (request):
        return render (request, "app/index.html")

def codu (request):
        return HttpResponse ("I LOVE U BRO")

def tommu (request):
        return HttpResponse ("hoe")

def greetings (request, name):
        return render(request, "app/greet.html", {
                "name": name.capitalize()
        })
