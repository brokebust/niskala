# Agile Collective base theme
This theme is a subtheme of Omega 4 and borrows heavily from the Omega provided ohm theme. The direct parent is omega however.

## Installation
Before you can create a subtheme you must ensure Drupal has been installed. You should have completed this step after installing with drush make. Please see the [instructions](http://gitlab.agile.coop/agile-base/tree/master/README.md).

To start theming the first step is to create a subtheme. There are two ways of doing this, using the drush omega-wizard command or the drush omega-subtheme. The two options are outlined below.

## Option 1: using the omega-wizard drush command

To do this ensure you are in your host machine and are in the drupal root. Then type:

	drush omega-wizard

Enter the name of your new theme, this is the full name rather than a machine name. Then enter the machine name for the theme.

Choose `Agile Collective base (Subtheme of Omega) - The base theme for Agile Collective sites.` at the next option.

Choose the Default starterkit.

Choose a destination for where you would like to install your new theme. This should be `sites/all/themes/custom` unless there is a good reason not to put it there.

Answer 'y' for the readme files, 'y' to enable your theme and 'y' to make your theme the default.

By answering 'y' to the last step Omega will download the libraries into the correct location in your new theme directory. Without these libraries your theme will not be able to make use of responsive sizes in older Internet
Explorer versions and some other useful features.

## Option 2: using the omega-subtheme drush command

This is slightly more advanced and requires you to set the parameters of the command properly. Below is an example, you should modify it to suit your needs:

	drush omega-subtheme "My New Site" --machine-name=my_new_site --destination=sites/all/themes/custom --basetheme=ac_base --with-libraries --enable --set-default

## Next steps

You can now start to modify your new theme. More instructions are contained in your subtheme [README.md](http://gitlab.agile.coop/ac_base/tree/master/starterkits/default/README.md) file.
