from django.urls import path

from telephone_book import views

urlpatterns = [
    path('telephone_book/', views.telephone_book_list),
    path('telephone_book/<int:pk>/', views.telephone_book_detail),
]