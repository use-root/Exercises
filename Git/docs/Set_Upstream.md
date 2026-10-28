# Set-Upstream

**Creates a permanent link** between your local branch and the branch on the server (GitHub).

When you run `git push -u origin main`, you are saying: _"Push my code, **and also remember that from now on, this local branch is linked to that remote branch**."_

Now, for the rest of the project's life, you can simply type:

- `git push`
- `git pull

The `-u` is for **convenience**. It saves you from having to type `origin main` every single time you want to share your code
