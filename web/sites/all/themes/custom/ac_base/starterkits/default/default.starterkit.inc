name = Default
description = The Agile Collective starterkit based on ac_base and Omega 4.
screenshot = screenshot.png
engine = phptemplate
core = 7.x

; Styles
stylesheets[all][] = css/{{ THEME SANITIZED }}.normalize.css
stylesheets[all][] = css/{{ THEME SANITIZED }}.hacks.css
stylesheets[all][] = css/{{ THEME SANITIZED }}.styles.css
stylesheets[all][] = css/{{ THEME SANITIZED }}.no-query.css

; Scripts
scripts[] = js/ckeditor.behaviors.js

; ========================================
; Regions
; ========================================
regions[branding] = Branding
regions[header] = Header
regions[navigation] = Navigation
regions[highlighted] = Highlighted
regions[help] = Help
regions[content] = Content
regions[sidebar_first] = First Sidebar
regions[sidebar_second] = Second Sidebar
regions[footer] = Footer

; ========================================
; Layout
; ========================================
layout[agile-hero][stylesheets][all][] = css/layouts/agile-hero/ac-base-agile-hero.layout.css

; ========================================
; Breakpoints
; ========================================
breakpoints[mobile] = (min-width: 0px)
breakpoints[narrow] = (min-width: 560px)
breakpoints[wide]   = (min-width: 851px)

; ========================================
; Settings
; ========================================
settings[toggle_logo] = 0
settings[toggle_name] = 1
settings[toggle_slogan] = 0
settings[toggle_node_user_picture] = 1
settings[toggle_comment_user_picture] = 1
settings[toggle_comment_user_verification] = 1
settings[toggle_favicon] = 1
settings[toggle_main_menu] = 1
settings[toggle_secondary_menu] = 1
settings[omega_toggle_front_page_content] = 1
settings[default_logo] = 1
settings[logo_path] = ""
settings[logo_upload] = ""
settings[default_favicon] = 1
settings[favicon_path] = ""
settings[favicon_upload] = ""
settings[omega_enable_warning] = 1
settings[omega_toggle_extension_layouts] = 1
settings[omega_layout] = agile-hero
settings[omega_toggle_extension_development] = 1
settings[omega_rebuild_theme_registry] = 0
settings[omega_rebuild_aggregates] = 0
settings[omega_browser_width_indicator] = 1
settings[omega_livereload] = 1
settings[omega_livereload_script] = http://localhost:35729/livereload.js
settings[omega_livereload_host] = localhost
settings[omega_livereload_port] = 35729
settings[omega_demo_regions] = 0
settings[omega_toggle_extension_compatibility] = 1
settings[omega_conditional_classes_html] = 1
settings[omega_apple_touch] = 1
settings[omega_cleartype] = 1
settings[omega_handheld_friendly] = 1
settings[omega_mobile_optimized] = 1
settings[omega_viewport] = 1
settings[omega_viewport_user_scaleable] = 1
settings[omega_chrome_edge] = 1
settings[omega_chrome_popup] = 0
settings[omega_chrome_notice] = 0
settings[omega_toggle_extension_assets] = 1
settings[omega_libraries][selectivizr][status] = 1
settings[omega_libraries][respond][status] = 0
settings[omega_libraries][pie][status] = 0
settings[omega_libraries][html5shiv][status] = 1
