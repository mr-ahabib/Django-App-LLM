from django.db import models

class Prompts(models.Model):
    text = models.CharField(max_length=255)
    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.text


class studentAssignment(models.Model):
    file = models.FileField(upload_to='uploads/')
    prompt = models.ForeignKey(Prompts, related_name='files', on_delete=models.CASCADE)
    uploaded_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.file.name
