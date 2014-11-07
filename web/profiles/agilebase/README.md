Agile Base
==========

Agile Base is a make file for drush which will install a set of defaults which make starting a new drupal project easier and standardises the process for Agile Collective.

Using [Drush Make](https://drupal.org/node/625094) we can run some simple commands and Drush will download all of the parts for our website, as defined in the make file. [See here](https://drupal.org/node/1089736) for the differences between installation profiles and distributions.

__The aims of Agile Base are to:__

*   __Provide a starting point for smaller projects, minimising the number of decisions that need to be made and save time.__
*   __Provide a standard base set of modules we default to using in our projects.__
*   __Provide a base theme and starterkit to make theming more consistent across projects.__

Setup guide
-----------

This guide presumes the following:

*    You're using the [Agile Parrot Vagrant box](http://gitlab.agile.coop/agileparrot).
*    You have Drush installed on your host machine.

If you're not using the agile parrot box, reading the full guide should still allow you to understand how to set up ready for development.

### Quickstart

Here's the quick version, make sure you have created a database and use the correct parameters for the --db-url

	cd /path/to/agileparrot/sites
	touch ../databases/site-name.sql
	drush make https://raw.githubusercontent.com/agilecollective/agile-base-make/master/install.make l.site-name/gitroot/web
	cd ../l.site-name
	ln -s gitroot/web web
	vagrant provision
	cd /vagrant_sites/site-name/gitroot/web
	drush si agilebase --db-url=mysql://root:root@127.0.0.1/site_dbname --account-name=admin --account-pass=admin
	drush cc all


You'll then need to edit your hosts file and add a line to allow you to access the site:

	sudo vim /etc/hosts
	192.168.50.4  l.site-name


You should now be able to access the site by visiting [http://site-name:8181](http://site-name:8181) using the credentials admin:admin.

Full setup guide
----------------

### 0.5 Install the Omega prerequisite RVM (once per system)

This step is only necessary the one time. It is a system wide change so will be picked up next time you create a site. Omega 4 uses specific versions of ruby and gems and the best way to allow Omega to control this is to use the ruby version manager (RVM). The following instructions are for OS X. Ubuntu users will need to follow a slightly different guide for installing RVM (probably apt-get install rvm).

First ensure you have [homebrew](http://brew.sh) installed. Then we'll install rvm and a stable version of ruby with

	\curl -sSL https://get.rvm.io | bash -s stable

Continue on to the steps below. You'll also need to install a specific version of ruby for compatibility with Omega but you need to do this from the ac_base directory so we'll pick this step back up later.

### 1. Create the Drupal installation using drush make

By using drush make with a remotely hosted make file we can easily install our chosen modules and clone the install profile in one simple command. The make file is hosted on github so that it is publically accessible which allows drush make to use it remotely. The repository is here: [https://github.com/agilecollective/agile-base-make](https://github.com/agilecollective/agile-base-make).

Navigate to a folder you'd like to place your Drupal install in.

	cd /path/to/folder

If you're using vagrant (parrot or agileparrot), which you shoudl be, you should navigate to it's sites folder from your host machine:

	cd /path/to/vagrantroot/sites

We can now trigger the drush make to install into a new folder and then move into that folder. Note that you should change l.newsite to whatever your new site is to be called. You should keep the prefix 'l.' to denote it is a local development site. In the following examples we are calling our new site 'mynewsite':

	drush make https://raw.githubusercontent.com/agilecollective/agile-base-make/master/install.make l.mynewsite/gitroot/web
	cd l.mynewsite

Drupal and all the required modules, themes and libraries will now be installed in `l.mynewsite/gitroot/web`

### 2. Create symlink

We use the gitroot/web subdirectory structure so we can initialise the repository in the gitroot folder so the .git folder and other assets will be above the web root and deployment to other systems is simpler, as we can symlink the gitroot/web to servers standard public document root (e.g /home/user1/pubic_html can point to gitroot/web).

	ln -s gitroot/web web

### 3. Provision the vhost and database

You will now want to get vagrant to set up a vhost and database for your new site. Place an empty sql file in your database directory of your vagrant box, named appropriately. So if your site is to be called mynewsite you would name your sql file mynewsite.sql like so:

1. On the host machine, whilst in the root of the vagrant box: `touch databases/mynewsite.sql`
2. Then run `vagrant provision` which will create the vhost and an empty database.

### 4. Run the installation process

We can run the installation process from the command line using drush site-install (or drush si for short). You'll need to change the parameters for at least `--site-mail` and `--account-mail` in the following example as well as provide the correct database name. You'll probably want to change the `--site-name` parameter as well. In your host machine somewhere in your Drupal directory run:

	drush si agilebase --db-url=mysql://root:root@127.0.0.1/mynewsite --account-name=root --account-pass=root --locale=en-GB --site-mail=user@agilecollective.com --site-name="Agile Base" --account-mail=user@agilecollective.com

By default the root MySQL login & password is root:root within the Agile Parrot Vagrant box, but you may want to change this. You'll also need to change the 'mynewsite' to the correct database name that you created in step 3.

### 5. Set up hosts file & access the site

To allow us to access the site from our browser you'll then need to edit your hosts file, you can do this on the command line using the VIM editor:

	sudo vi /etc/hosts

And adding a line similar to one of the following will allow us to access the site:

	192.168.50.4  l.mynewsite

You should now be able to access the site by visiting the domain you added to your hosts file and appending :8181 (as we are using port-forwarding) [http://l.mynewsite:8181](http://l.mynewsite:8181). A slightly more advanced but (preferred method)[https://github.com/computerminds/parrot/wiki/HTTP-stack] is to set up a firewall rule which will forward port 80 requests on localhost to port 8181 on the vagrant box which in turn get forwarded to port 80 for varnish. To do this (one time only per system) you need to run: `sudo ipfw add 100 fwd 127.0.0.1,8181 tcp from any to any 80 in`

### 5.5 Finish the rvm set up (once per system)

This step only needs to be done once on your system so skip forwards to 4 if you've already completed it.

Now you have all the files you need to finish the rvm install of the correct ruby version.

First cd into the ac_base theme as the theme contains the information rvm needs.

	cd sites/all/themes/custom/ac_base

You should see a message from rvm instructing you to install a specific version of ruby. Run the command as instructed:

	rvm install ruby-1.9.3-p545

You will now have that version of ruby available whenever you need it and won't have to install it again. A set of ruby gems is also needed to do all the Omega things we need to do so install that with:

	bundle install

Again, these installed gems will be associated with this version of ruby and will always be available through rvm so you won't need to install them again.

### 6. Set up a Git repository

@TODO - Add more in depth instructions here

	cd /agileparrot/sites/l.mynewsite/gitroot
	vim .gitignore

Paste contents of [agile-gitignore](gitlab.agile.coop/agile-base/tree/master/agile-gitignore) here.

	git init
	git add -A
	git comit -m "Initial commit"


Login to [Agile Gitlab](http://gitlab.agile.coop) and create a new project, use the global namespace, add the whole Agile Collective team to the repo (Admin->Team->Assign project to team of users-> Choose team of users -> Agile Collective->Assign)

Follow instructions provided by Gitlab to setting up a new repository.


### 7. Customise your new site

As we used the parameters --account-name=root --account-pass=root with the drush site-install command, we can login with the following credentials:

	username: root
	password: root

You may wish to download additional modules, themes and libraries and can now continue to customise the website for the project. Modules will be located in sites/all/modules/contrib. Themes will be located in sites/all/themes. Contrib themes are in sites/all/themes/contrib and custom themes are in sites/all/themes/custom. You should follow this pattern for modules too.

If you're unfamiliar with the ac_base theme and Omega you will want to read the instructions in the [README.md](http://gitlab.agile.coop/ac_base/tree/master/README.md) file in ac_base.

Advanced
--------

### Gitflow

You may wish to use the GitFlow methodology, and to reinforce this use the [GitFlow Git extension](https://github.com/nvie/gitflow), we can then run:

	git flow init

While in the git root of our project and select all of the git flow defaults.


Troubleshooting
---------------


#### Drush Make Errors

If you receive any error messages relating to Drush Make not being able to clone from gitlab, such as:

    Unable to clone agilepatterns-drupaltheme from git@gitlab.agile.coop:agilestarter.git     [error]

Check the user you are running drush make as has the correct permissions to clone, first of all by checking your SSH key is set up in Gitlab, and that your Gitlab user is a member of the repositories team.

#### File Permissions

As we are using an NFS share between the Vagrant Box and our host machine, we will need to allow full read/write permissions on settings.php

	chmod 777 settings.php

We will also want to enable full permissions on the files directory

	chmod sites/default/files