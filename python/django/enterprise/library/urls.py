from django.urls import path

from library import views

urlpatterns = [
    path('book/', views.book_list),
    path('book/<int:book_id>/', views.book_detail),
]
