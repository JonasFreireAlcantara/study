from django.db import models


class TelephoneBook(models.Model):
    name = models.CharField(max_length=200, blank=True, default='Anonymous')
    fone_number = models.CharField(max_length=30, blank=True, default='')
    e_mail = models.CharField(max_length=100, blank=True, default='')
