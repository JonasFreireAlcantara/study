# Generated by Django 2.1.5 on 2019-02-07 00:41

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='TelephoneBook',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(blank=True, default='Anonymous', max_length=200)),
                ('fone_number', models.CharField(blank=True, default='', max_length=30)),
                ('e_mail', models.CharField(blank=True, default='', max_length=100)),
            ],
        ),
    ]
