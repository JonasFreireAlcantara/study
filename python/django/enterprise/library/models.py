from django.db import models


class Book(models.Model):
    title = models.CharField(max_length=200, blank=True, default='')
    publication_year = models.IntegerField()
    edition_number = models.IntegerField()
    author = models.CharField(max_length=200, default='')
    publishing_company = models.CharField(max_length=100, blank=True, default='')

