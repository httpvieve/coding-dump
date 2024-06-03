from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.

# def index (request):
#         return HttpResponse("Welcome!")

def index (request):
        return render (request, "app/index.html")

def codu (request):
        return HttpResponse ("I LOVE U BRO")

def tommu (request):
        return HttpResponse ("hoe")

def prompt_greetings (request, name):
        return HttpResponse (f"Greetings, {name}!")
