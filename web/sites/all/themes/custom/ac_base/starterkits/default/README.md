# About this subtheme
This starter theme should be created using the `drush omega-wizard` command.

## Sass
The css is inherited from the parent theme's styles so if you want to override anything you should copy the files from the parent theme into this subtheme and modify here.

The Sass is a combination of three things, styles and ideas from Agile Patterns (now A-Frame), styles from the Ohm theme (subtheme of Omega) and some useful ideas gleaned from the web at large.

In the abstractions directory of ac_base you will find useful mixins. For example the agilebuttons partial provides mixins for buttons and the underlines partial provides mixins for making nicer (thiner) underlines for links. Create your own mixins in the abstractions directory of you subtheme.

To compile your Sass you should use the provided omega-guard drush command:

    drush omega-guard

This incorporates compass watch as well as livereload (see next section).

Make sure you follow the same folder structure and naming conventions for your Sass partials. This way the next person that looks at your theme will understand at a glance where styles are located. Try to avoid overly specific targeting
and try to make your Sass as modular as possible so it can applied easily in different situations.

The directory structure follows Drupal 8 and the SMACSS standard:

>Rulesets should be grouped into logical files that enforce the separation of concerns within the CSS, that can be aggregated efficiently and that can be easily overridden by themers.
>
>Drupal 8 follows a SMACSS-style categorization of its CSS rules:
>Base — CSS reset/normalize plus HTML element styling.
>Layout — macro arrangement of a web page, including any grid systems.
>Component — discrete, reusable UI elements.
>State — styles that deal with client-side changes to components.
>Theme — purely visual styling (“look-and-feel”) for a component.

## Layouts
To change the layout you can either select from an existing one in the theme's settings under layout, or you can create a new one. There is an example in /layouts.

To modify the grid sizes and order of the defealt agile hero layout you will want to make adjustments to the Sass in /sass/layouts/agile-hero. In particular the agile-hero.layout.scss file. In here you'll find mixin includes like:

	@include grid-span(8, 1);

This is telling the layout system to make this container 8 grid columns wide and to start at column 1. So if you want the classic layout with two sidebars and the first sidebar on the left side of the screen rather than after the content on the right, for the desktop size find the following:

	.l-region--sidebar-second {
				@include grid-span(3, 7);
				...}

and change it to:

	.l-region--sidebar-second {
				@include grid-span(3, 1);

That tells the layout system to make that container 3 columns wide and start it at column 1 (instead of column 7). You'll also want to change the .l-content container so it starts at column 4 now that you've moved the sidebar into its place.

If you want to learn more about this layout method you can research [singularity here](https://github.com/Team-Sass/Singularity).

Using the context_omega module you can change layouts under different conditions like path or other context conditions.

## Livereload
Omega comes with guard and livereload which is a really nice way of getting livereload functionality without configuration. Livereload will inject any css changes into your open browsers everytime you update a Sass file. That means no more reloading the page to see your changes. To use it simply use the provided drush command and choose your theme from the list (or provide is as a parameter):

	drush omega-guard
or

	drush omega-guard mynewtheme

You'll also want a livereload plugin for your browser:

* [Chrome](https://chrome.google.com/webstore/detail/livereload/)
* [Firefox](http://download.livereload.com/2.0.8/LiveReload-2.0.8.xpi)
* [Safari](http://download.livereload.com/2.0.9/LiveReload-2.0.9.safariextz)