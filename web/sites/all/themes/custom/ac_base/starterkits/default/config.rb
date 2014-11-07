##
## This file is only needed for Compass/Sass integration. If you are not using
## Compass, you may safely ignore or delete this file.
##
## If you'd like to learn more about Sass and Compass, see the sass/README.txt
## file for more information.
##

# Default to development if environment is not set.
saved = environment
if (environment.nil?)
  environment = :development
else
  environment = saved
end

# Location of the theme's resources.
css_dir = "css"
sass_dir = "sass"
images_dir = "images"
generated_images_dir = images_dir + "/generated"
javascripts_dir = "js"

# Require any additional compass plugins installed on your system.
require 'compass-normalize'
require 'rgbapng'
require 'toolkit'
require 'susy'
require 'sass-globbing'

# Make a copy of sprites with a name that has no uniqueness of the hash. This
# is the production version. That way we can ignore the generated directory
# in gitignore.
on_sprite_saved do |filename|
  if File.exists?(filename)
    newname = filename.gsub(%r{-s[a-z0-9]{10}\.png$}, '.png')
    newpath = newname.gsub(%r{/generated}, '')
    FileUtils.cp filename, newpath
  end
end

# Replace in stylesheets generated references to sprites
# by their counterparts without the hash uniqueness, but only whilst in
# production mode.
if (environment == :production)
  on_stylesheet_saved do |filename|
    if File.exists?(filename)
      css = File.read filename
      replace = css.gsub(%r{-s[a-z0-9]{10}\.png}, '.png')
      replace = replace.gsub(%r{/generated}, '')
      File.open(filename, "w") {|file| file.puts replace}
    end
  end
end

##
## You probably don't need to edit anything below this.
##

# You can select your preferred output style here (:expanded, :nested, :compact
# or :compressed).
output_style = (environment == :production) ? :expanded : :nested

# To enable relative paths to assets via compass helper functions. Since Drupal
# themes can be installed in multiple locations, we don't need to worry about
# the absolute path to the theme from the server omega.
relative_assets = true

# Conditionally enable line comments when in development mode.
line_comments = (environment == :production) ? false : true

# Output debugging info in development mode.
sass_options = (environment == :production) ? {} : {:debug_info => true}

# Add the 'sass' directory itself as an import path to ease imports.
add_import_path 'sass'
