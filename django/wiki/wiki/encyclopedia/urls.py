from django.urls import path

from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("wiki/<str:title>", views.entry_page, name="entry_page"),
    path("new", views.new_page, name="new_page"),
    path("random_page", views.random_page, name="random"),
    path("edit/<str:title>", views.modify_page, name="modify"),
    path("search", views.search_entry, name="search"),
    
]
