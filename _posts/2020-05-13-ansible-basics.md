---
title: Ansible: Automating your deployments
layout: post
author: Sumit Kar
date: '2020-05-13 21:03:23 +0530'
category: tech
summary: 'Since the world is moving into the DevOps model, 
  and the industry started focusing on automation, I thought 
  of sharing something related to automation for deployment. 
  Server-side deployment can be automated using several tools. 
  One of which is Ansible. Ansible is a management tool that 
  helps to maintain the cluster of machines.'
thumbnail: ansible-basics.jpg
---


Since the world is moving into the DevOps model, and the industry started focusing on automation, I thought of sharing something related to automation for deployment. 
Server-side deployment can be automated using several tools. One of which is Ansible. Ansible is a management tool that helps to maintain the cluster of machines.

There are several configuration-management tools out there why we should go with Ansible. For that there are below reasons 

- Idempotent- Ansible’s whole architecture is structured around the concept of idempotency. The core idea here is that you only do things if they are needed and that things are repeatable without side effects. 
- Agentless - There is no software that needs to be installed on the client system. We can use ansible as long we can ssh 
- Modules - we create the new module in the ansible and add it to the ansible 
- Tiny Learning Curve- Ansible is quite easy to learn. It doesn’t require any extra knowledge. With basic Linux knowledge this can be learnt. 

Ansible needs 3 files:

**hosts** [ Inventory file: This file can contain the list of servers. It can be a list of DNS name and IP. ]
```
[web]
host1.example.com
192.168.1.122
host3.example.com

[db]
host4.example.com
host5.example.com
host6.example.com
```
The following code can added to try this locally 
```
[all:vars]
ansible_connection=local
```


**ansible.cfg** [ Config file ]
Order of preference of confirguation file 
1. File specified by the ANSIBLE_CONFIG environment variable 
2. ./ansible.cfg (ansible.cfg in the current directory) 
3. ~/.ansible.cfg (.ansible.cfg in your home directory) 
4. /etc/ansible/ansible.cfg 

```
[defaults]
inventory = hosts 
remote_tmp      = ~/.ansible/tmp
local_tmp       = ~/.ansible/tmp
remote_user = ubuntu 
private_key_file = ansible.pem
#vault_password_file = /path/to/vault_password_file
#executable = /bin/sh
#ask_pass        = False
host_key_checking = False 
interpreter_python = auto
[privilege_escalation]
#become = False
#become_method = sudo
#become_ask_pass = False


[persistent_connection]
#connect_timeout = 30
#command_timeout = 30
```

**play-nginx.yml** [Play file]
```
---
- hosts: web
  become: yes
  tasks:
    - name: ensure nginx is at the latest version
      apt: name=nginx state=latest
    - name: copy the content of the web site
      copy:
        src: index.html
        dest: /var/www/html/
    - name: start nginx
      service:
          name: nginx
          state: started
```




### Ansible Ad-hoc command 
The Ad-Hoc command is the one-liner ansible command that performs one task on the target host. It allows you to execute simple one-line task against one or group of hosts defined on the inventory file configuration. 

adhoc command has the two parts 
List of host that you want to run the module 
ansible module to run 

`$ ansible all -m ping` 

The first parameter all tells we are performing the task against the all host 
The second parameter m tells we are going to use ping module 

To Know the list of modules type the below command in the terminal 

`$ ansible-doc -l | more`

To Find the detail of modules 

`$ ansible-doc <module-name>`



## Performing basic task using ansible command 

### Installing packages 

**Run the below command in the terminal and see the output**

`$ ansible testserver -m shell -a "whoami"` 

**Run the below command in the terminal and see the output and compare with above one**

`$ ansible testserver -m shell -a "whoami" --become` [ `--become` is a parameter used to become root user ]

**Type the below command in the terminal to install nginx**

`$ ansible testserver -m apt -a 'name=nginx state=latest' --become` 

**starting the services : Run the below command in the terminal to start the service**

`$ ansible -m service -a "name=nginx state=started enabled=yes" testserver --become`

**Run the below command in the terminal to see ths status of the ngnix** 

`$ ansible testserver -m shell -a "service nginx status" --become`

**Run the below command to stop the service** 

`$ ansible -m service -a "name=nginx state=stopped enabled=yes" testserver --become`


### File module 

**Run the below command in the terminal to find the existence of the folder**
`$ ansible -m file -a "path=/usr/share/nginx/html state=directory" testserver --become`

**Copy module: Run the below command in the terminal to copy the file from host to node (Copy module take 2 parameter : Source and Destination)**

`$ ansible -m copy -a "src=a.txt dest=/usr/share/nginx/html/" testserver --become` 


### Ansible setup module 

**The setup module is used to gather the information about the host**  
`$ ansible testserver -m setup` 
`$ ansible testserver -m setup -a "filter=*ipv4"`


## Writing your first playbook 

Playbooks are list of plays grouped together and plays is group of tasks and task call modules 
Playbooks are generally written in the yaml format 
Note : we can also write the playbook in the json format 

To run the playbook we can simply use the ansible-playbook and followed by the playbook name 

Every playbook has 2 components 
- hosts - list of host in which we want to run the task 
- task - task need to be performed  


**Run the below command** 
`$ ansible-playbook <playbook-name>.yaml` 

**To know whether the syntax of the playbook was correct we can use** 
`$ ansible-playbook --syntax-check <playbook-name>.yaml`



## Ansible Roles 
Roles in Ansible are next level abstraction of playbook 
Roles are way to organize the playbook in the efficient manner so that we can use it later. 
Type the below command to see the list of command of available using the ansible-galaxy 

`$ ansible-galaxy -h` 

The syntax to create the role was 

`$ ansible-galaxy init <role-name>` 

Files inside the Role 

- Default - Data about the role / application default variable eg:port no 
- files - put the static files 
- Handlers - handler are kept here 
- meta - Information about the role 
- task - Task are kept here 
- templates - Similar to files but they are dynaimic 
- vars - Same as Default it has high prority  


## Ansible Vault 
Ansible vault to encrypt the playbook and store them safely 
Basic Ansible vault command 
- create 
- encrypt 
- decrypt 
- view 
- rekey 

### Create 
Type the below command in the terminal to create the playbook 
`$ ansible-vault create filename.yaml` 

### Edit 
Type the below command in the terminal to edit the encrypted playbook 
`$ ansible-vault edit filename.yaml` 

### View 
Type the below command in the terminal to view the encrypted playbook 
`$ ansible-vault view filename.yaml` 

### Rekey 
Rekey is the command used to change the password 
`$ ansible-vault rekey filename.yaml` 

### Encrypt 
Type the below command in the terminal to encrypt the existing playbook 
`$ ansible-vault view filename.yaml` 

### Decrypt 
`Type the below command in the terminal to de-encrypt the existing playbook` 
`$ ansible-vault view filename.yaml` 

### Running the encrypted playbook 
Type the below command in the terminal to run the encrypted playbook 
`$ ansible-playbook filename.yml --ask-vault-pass`



Ansible is a powerful tool and this can not only be used for automating deployment. 
It is also used to harden Operating System and applying patch.

Try out basic ansible commands :  https://github.com/karsumit94/ansible-example
