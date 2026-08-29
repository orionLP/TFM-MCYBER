# TFM-MCYBER

## Installation

After cloning this repostiroy, to run the code, you need to follow the next steps:

First create a virtual environment with python:

```{bash}
python3 -m venv .venv
```

Then use the virtual environment:

```{bash}
source ./.venv/bin/activate
```

Next, you need to install the required dependencies:

```{bash}
pip3 install -r requirements.txt
```

Then, to pull the datasets from the DVC repository you are going to need a DagsHub account. Now visit the
DagsHub repository at https://dagshub.com/orionLP/TFM-MCYBER, click at the "Data" button and then look
at the "Setup credentials" section. You will find the commands below (but with your username and auth token,
which will be hidden, but you can click a button to make it visible):

```{bash}
dvc remote modify origin --local auth basic
dvc remote modify origin --local user <your DagsHub user>
dvc remote modify origin --local password <you DagsHub auth token>
```

## Datasets and code organitzation


## Using DVC

