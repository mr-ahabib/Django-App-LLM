from django.contrib import admin

# Register your models here.
from .models import studentAssignment
from .models import Prompts

admin.site.register(studentAssignment)
admin.site.register(Prompts)