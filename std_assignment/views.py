from django.shortcuts import render
from django.http import JsonResponse
from .models import Prompts, studentAssignment
from django.views.decorators.csrf import csrf_exempt
def home(request):
    return render(request, 'home.html')
@csrf_exempt
def index(request):
    if request.method == 'POST':
        files = request.FILES.getlist('files')
        prompt_text = request.POST.get('prompt')

        if files and prompt_text:
            prompt = Prompts.objects.create(text=prompt_text)

            for file in files:
                studentAssignment.objects.create(file=file, prompt=prompt)

            
            context = {
                'success_message': 'Files and prompt have been successfully uploaded!'
            }
            return render(request, 'index.html', context)
        else:
            
            context = {
                'error_message': 'Please provide both files and a prompt.'
            }
            return render(request, 'index.html', context)

    return render(request, 'index.html')

