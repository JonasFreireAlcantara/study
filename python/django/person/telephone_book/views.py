from django.http import JsonResponse, HttpResponse
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
            return JsonResponse(serializer.data)


@csrf_exempt
def telephone_book_detail(request, pk):
    try:
        telephone_book = TelephoneBook.objects.get(pk=pk)
    except TelephoneBook.DoesNotExist:
        return HttpResponse(status=404)

    if request.method == 'GET':
        serializer = TelephoneBookSerializer(telephone_book, many=True)
        return JsonResponse(serializer.data)

    elif request.method == 'PUT':
        data = JSONParser().parse(request)
        serializer = TelephoneBookSerializer(telephone_book, data=data)
        if serializer.is_valid():
            serializer.save()
            return JsonResponse(serializer.data)
        return JsonResponse(serializer.errors, status=400)

    elif request.method == 'DELETE':
        telephone_book.delete()
        return HttpResponse(status=204)
