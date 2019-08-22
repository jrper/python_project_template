# An example template for a Python package

Set up to be tested by Azure pipelines

To register a new pipelines build:

```
az devops project create --name <project_name>
az pipelines create --name <project_name> --repository <repo_url>
```

[![Build Status](https://dev.azure.com/jrper/python_project_template/_apis/build/status/jrper.python_project_template?branchName=master)](https://dev.azure.com/jrper/python_project_template/_build/latest?definitionId=3&branchName=master)