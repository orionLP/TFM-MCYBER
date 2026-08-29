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

Then you will need to execute the following command, changing the path to the one you cloned the repository
into:

```{bash}
export PYTHONPATH="${PYTHONPATH}:<path were you cloned the repository into>/TFM-MCYBER"
```

Then, to pull the datasets from the DVC repository you are going to need a DagsHub account. Now visit the
DagsHub repository at https://dagshub.com/orionLP/TFM-MCYBER, click at the "Data" button and then look
at the "Setup credentials" section. You will find the commands below (but with your username and auth token,
which will be hidden, but you can click a button to make it visible), you can use them, but you will need to
change the name "origin" with "storage":

```{bash}
dvc remote modify storage --local auth basic
dvc remote modify storage --local user <your DagsHub user>
dvc remote modify storage --local password <you DagsHub auth token>
```

Then you will be able to pull the data from DagsHub (this might take a few minutes):

```{bash}
dvc pull
```

To use the known packers you will need to install UPX and Wine with the following commands:

```{bash}
sudo apt update
sudo apt install upx-ucl
sudo apt install wine
```

## Datasets and code organitzation

The commits at which an experiment were done and metrics were published have been tagged. As we worked, changes in the code might have changed the output datasets that are created with pipelines, so if you want to see the original output dataset of a technique as it was evaluated you can use the following commands to change the working evironment and datasets to the ones we used:

```{bash}
git checkout <tag name>
dvc checkout
```

You may sometimes get an error (possibly about missing data), if that happns do a `dvc pull` before the `dvc checkout` as such:

```{bash}
git checkout <tag name>
dvc pull
dvc checkout
```

The following is a list of each tag corresponding to an evasion techique. If you go to the commit of any of these tags with git and dvc, you will find the version of the code we used to create the output dataset which we used to evaluate that technique. You will also find the exact samples in the output dataset that were genereated to perform the evaluation of that technique, as well as the metrics obtained with those samples.

We used DVC pipelines to automate the creation of the output datasets, so if at any point you want to run them to execute our code and regenerate the output datasets, you can use the command `dvc repro`, which will run the necessary code to regenerate the output datasets. However, `dvc repro` does not execute the pipelines when there have been no changes in the dependencies to create an output dataset. Therefore, depending on the commit you are and the version of the dataset you have, it might not execute anything if it is unnecessary.

- `algorithm-key-obfuscation`: This is the study were we evaluated changed to the encryption algorithm, the encryption key and obfuscated some versions of the code.

  The code for this is in `src/crypters/multiple_information_reveal`, the output datasets are located at `data/crypters/exe/x86/multiple_information_reveal`, and the metrics are at `metrics/crypter_info_reveal`

- `code-obfuscation`: This is the study were we evaluated using code obfuscation.

  The code for this is in `src/crypters/code_obfuscation/`, the output datasets are located at `data/crypters/exe/x86/code_obfuscation/opaque_ifs`, and the metrics are at `metrics/crypter_code_obfuscation_opaque_ifs`.

- `code-stops`: This is the study were we stopped the execution of samples at specific points to evaluate dynamic defenses.
  
  The code for this is at `src/custom/code_stop`, the output datasets are located at `data/custom/code_stop/crypters_idata_obfuscation_dynamic_api_resolution`, and the metrics are at `metrics/custom_code_stop`.

- `dynamic-api-resolution`: This is the study were we evaluated the use of code obfuscation, junk API call insertion, and dynamic api resolution.

  The code for this is in `src/crypters/idata_obfuscation_dynamic_api_resolution`, the output datasets are located at `data/crypters/exe/x86/idata_obfuscation/dynamic_api_resolution`, and the metrics are at `metrics/crypter_idata_obfuscation_dynamic_api_resolution`.

- `final-pipeline`: Final evaluation of our evasion techniques.

  The code for this is in `src/final_pipeline`, the output datasets are located at `data/final_pipeline`, and the metrics are at `metrics/final_pipeline`.

- `idata-obfuscation`: This is the study were we evaluated the use of code obfuscation and junk API call insertion.

  The code for this is in `src/crypters/idata_obfuscation`, the output datasets are located at `data/crypters/exe/x86/idata_obfuscation/opaque_calls`, and the metrics are at `metrics/crypter_idata_obfuscation_opaque_function_calls`.

- `packers`: This is the study were we evaluated the use of known packers.

  The code for this is in `src/packers`, the output datasets are located at `data/packed/exe/x86`, and the metrics are at `metrics/packed_v1.0.0.json`.

- `survival-kaspersky-bitdefender`: This is were we did a survival study with kasperksy and bitdefender.

  The code for this is in `src/crypters/idata_obfuscation_dynamic_api_resolution`, the output datasets are located at `data/crypters/exe/x86/idata_obfuscation/static_survival`, and the metrics are at `metrics/static_survival_kaspersky_bitdefender`.

- `tutorial-crypter`: This is were we evaluated the XOR crypter.
  
  The code for this is in `src/crypters/tutorial`, the output datasets are located at `data/crypters/exe/x86/tutorial`, and the metrics are at `metrics/crypter_tutorial_v1.0.0.json`.

- `ablation-code-algorithm`: The ablation study for the samples of both the code obfuscation and the study of changes in algorithm, code and keys.

  The code for both evasion techniques is in `src/custom/ablation`. In the case of the code obfuscation the output dataset is at `data/custom/ablation/code_obfuscation/opaque_ifs` and the metrics are at `metrics/custom_ablation/second_experiment` in the file `opaque_ifs.json`. The name of the folder for the metrics changed, and in the current state of the repository, it is called `metrics/custom_ablation/second_experiment_information_reveal_opaque_ifs`.

  In the case of the changes in algorithm, code and keys the output dataset is at `data/custom/ablation/multiple_information_reveal` and the metrics are at `metrics/custom_ablation/second_experiment` in file `information_reveal.json`. As before, the name of the folder for the metrics changed, and in the current state of the repository it is called `metrics/custom_ablation/second_experiment_information_reveal_opaque_ifs`.

- `ablation-idata-obfuscation`: ablation study of the samples for idata obfuscation.

  The code for this is in `src/custom/ablation`, the output datasets are located at `data/custom/ablation/idata_obfuscation/opaque_calls`, and the metrics are at `metrics/custom_ablation/third_experiment_idata_obfuscation_opaque_calls`.

- `ablation-packers-raw-tutorial`: ablation study of the samples in the packing experiment, the raw dataset, and the custom XOR crypter.

  The code for this is for the three in `src/custom/ablation`. In the case of the packers the output datasets are located at `data/custom/ablation` in the folders `mpress`, `petite`, and `upx`. In the case of the raw dataset the output dataset is located in `data/custom/ablation/raw`. In the case of the custom XOR crypter the dataset is located in `data/custom/ablation/tutorial`. The metrics for the three of these experiments are located in `metrics/custom_ablation` in the file `custom_ablation_v1.0.0.json`. In this case the directory where the metrics are found has changed, and in the current state of the repository they are in the directory `metrics/custom_ablation/first_experiment_all_initial_techniques`



