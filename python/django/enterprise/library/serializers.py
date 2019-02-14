from rest_framework import serializers

from library.models import Book


class BookSerializer(serializers.ModelSerializer):
    class Meta:
        model = Book
        fields = ('id', 'title', 'publication_year', 'edition_number', 'author', 'publishing_company')

    def create(self, validated_data):
        return Book.objects.create(**validated_data)

    def update(self, instance, validated_data):
        instance.title = validated_data.get('title', instance.title)
        instance.publication_year = validated_data.get('publication_year', instance.publication_year)
        instance.edition_number = validated_data.get('edition_number', instance.edition_number)
        instance.author = validated_data.get('author', instance.author)
        instance.publishing_company = validated_data.get('publishing_company', instance.publishing_company)
        instance.save()
        return instance
