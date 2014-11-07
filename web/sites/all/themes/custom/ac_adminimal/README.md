# Agile Collective Adminimal theme.
This theme is used as a way of overriding the adminimal theme to provide
customisations and fixes. For example it contains some css to override the
output of the environment indicator so the admin menu isn't wholly coloured and
which would probably not get committed to the adminimal theme repository.

It is also an opportunity for themers to add their own hacks or changes to
administration css on a project by project basis, rather than finding ways to
inject their css when the admin theme is loaded by using a custom module or
similar technique. This way it's just a simple child theme that inherits all of
the goodness from its parent and can continue to do so when the parent is
updated.

# Sass
Sass has been provided but its up to the themer to decide how they want to
implement it. There is a simple overrides.scss file which can be added to.
