from django.http import JsonResponse
from django.shortcuts import render
from django.views.decorators.csrf import csrf_exempt
from rest_framework.parsers import JSONParser

from telephone_book.models import TelephoneBook
from telephone_book.serializers import TelephoneBookSerializer


@csrf_exempt
def telephone_book_list(request):
    if request.method == 'GET':
        phone_book_list = TelephoneBook.objects.all()
        serializer = TelephoneBookSerializer(phone_book_list, many=True)
        return JsonResponse(serializer.data, safe=False)

    elif request.method == 'POST':
        data = JSONParser().parse(request)
        serializer = TelephoneBookSerializer(data=data) # Create
        if serializer.is_valid():
            serializer.save()
            return JsonResponse(serializer.data, status=)