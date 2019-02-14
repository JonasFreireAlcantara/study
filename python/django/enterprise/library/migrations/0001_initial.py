# Generated by Django 2.1.5 on 2019-02-14 01:39

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Book',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('title', models.CharField(blank=True, default='', max_length=200)),
                ('publication_year', models.IntegerField()),
                ('edition_number', models.IntegerField()),
                ('author', models.CharField(default='', max_length=200)),
                ('publishing_company', models.CharField(blank=True, default='', max_length=100)),
            ],
        ),
    ]
