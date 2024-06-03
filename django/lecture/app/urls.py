from django.urls import path
from . import views

urlpatterns = [
        
    path("", views.index, name="index"),
    path("<str:name>", views.prompt_greetings, name="greet"),
    path("codu", views.codu, name="codu"),
    path("tommu", views.tommu, name="tommu")
]
