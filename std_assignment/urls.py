from django.contrib import admin
from django.urls import path
from std_assignment import views

urlpatterns = [
    path('', views.home,name='home'),
    path('index',views.index,name='index'),
   
]
