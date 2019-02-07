from rest_framework import serializers
from telephone_book.models import TelephoneBook


class TelephoneBookSerializer(serializers.ModelSerializer):

    class Meta:
        model = TelephoneBook
        fields = ('id', 'name', 'fone_number', 'e_mail')

    def create(self, validated_data):
        return TelephoneBook.objects.create(**validated_data)

    def update(self, instance, validated_data):
        instance.name = validated_data.get('name', instance.name)
        instance.fone_number = validated_data.get('fone_number', instance.fone_number)
        instance.e_mail = validated_data.get('e_mail', instance.e_mail)
        instance.save()
        return instance
