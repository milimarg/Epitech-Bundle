#!/bin/bash

export ANSIBLE_VAULT_PASSWORD_FILE=/tmp/.vault_pass
cat .config_env.yml > $ANSIBLE_VAULT_PASSWORD_FILE
cp $ANSIBLE_VAULT_PASSWORD_FILE group_vars/all.yml
ansible-vault encrypt group_vars/all.yml > /dev/null
ansible-playbook -i production playbook.yml
