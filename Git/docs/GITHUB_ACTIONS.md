# CI/CD

Continuous Integration and Continuous Development are virtual machines that you can use to test your code or deploy your code, depending on your work.

So I use it to test my katas and deploy my Frontend Mentor challenges. It's easier to understand what it is doing, because it uses a natural language and shell commands.

### My Workflows:

I might change the config or the way that I'm doing this right now, but for now it's working and I know probably it's a better way to do this, so that's why my workflows will be in constant change, especially the Testing Workflow.

###### DEPLOY ONLY FRONTED MENTOR PAGES.

```yaml
name: "Deploy Web to GitHub Pages \U000F1362"
on:
  push:
    branches:
      - main
    paths:
      - 'Web/FrontendMentor/**'
jobs:
  deploy:
    runs-on: ubuntu-latest
    steps:
      - name: "Checkout \U000F0DA1"
        uses: actions/checkout@v4
        with:
          fetch-depth: 0
      - name: Deploy 
        uses: peaceiris/actions-gh-pages@v3
        with:
         github_token: ${{ secrets.GITHUB_TOKEN }}
          publish_dir: ./Web/FrontendMentor
name: Deploy Web to GitHub Pages
```

###### TESTING PUSH / PULL REQUEST

```yaml
name: CI Pipeline
on:
  pull_request:
    branches:
      - main
  push:
    branches:
      - main
jobs:
  changes:
    runs-on: ubuntu-latest
    outputs:
      oop: ${{ steps.filter.outputs.oop }}
      os: ${{ steps.filter.outputs.os }}
      katas: ${{ steps.filter.outputs.katas }}
      bash_offensive: ${{ steps.filter.outputs.bash_offensive }}
      python_offensive: ${{ steps.filter.outputs.python_offensive }}
      git_ej_py: ${{ steps.filter.outputs.git_ej_py }}
    steps:
      - uses: actions/checkout@v4
      - uses: dorny/paths-filter@v3
        id: filter
        with:
          filters: |
            os:
              - 'OS/exercises/**'
            oop:
              - 'OOP/exercises/**'
            katas:
              - 'Katas/CP/**'
            bash_offensive:
              - 'Hacking/bash_offensive/exercises/**'
            python_offensive:
              - 'Hacking/python_offensive/exercises/**'
            git_ej_py:
              - 'Git/exercises/**'
  test-git-ej:
    needs: changes
    if: ${{ needs.changes.outputs.git_ej_py == 'true' }}
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
        with:
          fetch-depth: 0
      - name: This is only a test in Git dir
        run: |
          if [ "${{ github.event_name }}" == "pull_request" ]; then
            change_folder=$(git diff --name-only origin/main...HEAD | grep "Git/exercises" | head -n 1 | cut -d/ -f1-3)
          else
            change_folder=$(git diff-tree --no-commit-id --name-only -r HEAD | grep "Git/exercises" | head -n 1 | cut -d/ -f1-3)
          fi
          cd $change_folder
          python -m unittest discover -s tests -t .
  test-oop:
    needs: changes
    if: ${{ needs.changes.outputs.oop == 'true' }}
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
        with:
          fetch-depth: 0
      - name: Run OOP Test in Java
        run: |
          change_folder=$(git diff --name-only origin/main...HEAD | grep "OOP/exercises/" | head -n 1 | cut -d/ -f1-3)
          echo "Testing Java in $change_folder"
  test-os:
    needs: changes
    if: ${{ needs.changes.outputs.os == 'true' }}
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
        with:
          fetch-depth: 0
      - name: Run OS Test in C
        run: |
          change_folder=$(git diff --name-only origin/main...HEAD | grep "OS/exercises/" | head -n 1 | cut -d/ -f1-3)
          echo "Testing C in $change_folder"
  test-katas:
    needs: changes
    if: ${{ needs.changes.outputs.katas == 'true' }}
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
        with:
          fetch-depth: 0
      - name: Run Kata Test in C++
        run: |
          if [ "${{ github.event_name }}" == "pull_request" ]; then
            RANGE="origin/main...HEAD"
          else
            RANGE="HEAD~1 HEAD"
          fi
          EXERCISES=$(git diff --name-only $RANGE | grep "Katas/CP" | cut -d/ -f3 | sort -u)
          if [ -z "$EXERCISES" ];then
            echo  "No changes detected in Katas/CP directories."
            exit 0;
          fi

          cd Katas/CP

          for folder in "$EXERCISES"; do
            echo "Testing exercises in folder: $folder"
            bash test_runner.sh $folder
          done
  test-bash_offensive:
    needs: changes
    if: ${{ needs.changes.outputs.bash_offensive == 'true' }}
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
        with:
          fetch-depth: 0
      - name: Run Bash Test
        run: |
          change_folder=$(git diff --name-only origin/main...HEAD | grep "Hacking/bash_offensive/exercises/" | head -n 1 | cut -d/ -f1-4)
          echo "Testing Bash in $change_folder"
  test-python_offensive:
    needs: changes
    if: ${{ needs.changes.outputs.python_offensive == 'true' }}
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
        with:
          fetch-depth: 0
      - name: Run Python Test
        run: |
          change_folder=$(git diff --name-only origin/main...HEAD | grep "Hacking/python_offensive/exercises/" | head -n 1 | cut -d/ -f1-4)
          echo "Testing Python in $change_folder"
```
