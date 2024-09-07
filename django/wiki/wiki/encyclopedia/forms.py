from django import forms

class ModifyEntry(forms.Form):
    modified_content = forms.CharField(
        label = "Update description: ",
        strip = True,
        widget = forms.Textarea(attrs={'style': 'width: 80%; height: 50%; display: block;'}
    )
    )

class EntryForm(forms.Form):
    title = forms.CharField(label="Title: ", max_length=200, required=True,
        widget = forms.Textarea(attrs={'style': 'width: 80%; height: 40px; display: block;'})
        )
    content = forms.CharField(
        label = "Content:",
        widget = forms.Textarea(attrs={'style': 'width: 80%; height: 50%;'}
    )
    )