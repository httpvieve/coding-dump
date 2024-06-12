from django.urls import path
from . import views

urlpatterns = [
        
    path("", views.index, name="index"),
    path("codu", views.codu, name="codu"),
    path("<str:name>", views.greetings, name="greet"),
    path("tommu", views.tommu, name="tommu"),
]
