from django.http import JsonResponse, HttpResponse
from django.views.decorators.csrf import csrf_exempt
from rest_framework.parsers import JSONParser

from library.models import Book
from library.serializers import BookSerializer


@csrf_exempt
def book_list(request):
    if request.method == 'GET':
        """
            Get a list of all books
        """
        books = Book.objects.all()
        serializer = BookSerializer(books, many=True)
        return JsonResponse(serializer.data, safe=False)

    elif request.method == 'POST':
        """
            Insert one book to the list
        """
        new_data = JSONParser().parse(request)
        serializer = BookSerializer(data=new_data)
        if serializer.is_valid():
            serializer.save()
            return JsonResponse(serializer.data, status=201)
        return JsonResponse(serializer.errors, status=400)


@csrf_exempt
def book_detail(request, book_id):
    try:
        book = Book.objects.get(id=book_id)
    except Book.DoesNotExist:
        return HttpResponse(status=404)

    if request.method == 'GET':
        """
            Retrieve the book
        """
        serializer = BookSerializer(book)
        return JsonResponse(serializer.data)

    elif request.method == 'PUT':
        new_data = JSONParser().parse(request)
        serializer = BookSerializer(book, data=new_data)
        if serializer.is_valid():
            serializer.save()
            return JsonResponse(serializer.data)
        return HttpResponse(status=400)

    elif request.method == 'DELETE':
        book.delete()
        return HttpResponse(status=204)
