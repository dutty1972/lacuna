# enlightenment foundation library elementary UI preprocessor
## Why not run a hello world?
You will have to have gcc and elementary installed.

	./lpp elm-ui hello.c -o hello `(pkg-config --cflags --libs elementary)`
	./hello

or, just simply

	sh hello.c


## processing flow

	cpp -dD file.c | sed '/__STDC/d' | ./lpp-elm-ui | cpp | gcc -x cpp-output -
	 `-- #include, #define  `-- avoid warning           `-- expand macros

## how to use?

	object:+object_type	parameters(which will be directly copied into c)
	object:set_method	parameters(which will be directly copied into c)
	object::get_method	parameters(which will be directly copied into c)
	object:-event_name	parameters(which will be directly copied into c)
	object:=object_type
	object_type:*object

## configuration file
example:

	evas_object		/						/
		weight		size_hint_weight_set	size_hint_weight_get
		resize		resize					/
		/ / /
		EXPAND		EVAS_HINT_EXPAND
		FILL		EVAS_HINT_FILL
		/ /

	elm_object		evas_object				/
		/ / /
		/ /

	elm_win			elm_object				util_standard_add
		resize_object	resize_object_add	/
		/ / /
		/ /

	elm_box			elm_object				/
		pack		pack_end				/
		pack_end	pack_end				/
		/ / /
		/ /


Syntax:

	"/"		denotes to "null".
	"/ / /"	denotes to "end of method list"
	"/ /"	denotes to "end of substitution list"

	blank lines are ignored.

	<prefix>_<type> <BLANKS> <parent> <BLANKS> <add_method>
		<method> <BLANKS> <set_method> <BLANKS> <get_method>
		<method> <BLANKS> <set_method> <BLANKS> <get_method>
		<method> <BLANKS> <set_method> <BLANKS> <get_method>
		<method> <BLANKS> <set_method> <BLANKS> <get_method>
		...
		<method> <BLANKS> <set_method> <BLANKS> <get_method>
		/ / /
		<subs_from> <BLANKS> <subs_to>
		<subs_from> <BLANKS> <subs_to>
		<subs_from> <BLANKS> <subs_to>
		<subs_from> <BLANKS> <subs_to>
		...
		<subs_from> <BLANKS> <subs_to>
		/ /
	<prefix>_<type> <BLANKS> <parent> <BLANKS> <add_method>
		<method> <BLANKS> <set_method> <BLANKS> <get_method>
		...
		<method> <BLANKS> <set_method> <BLANKS> <get_method>
		/ / /
		<subs_from> <BLANKS> <subs_to>
		...
		<subs_from> <BLANKS> <subs_to>
		/ /
	...
	<prefix>_<type> <BLANKS> <parent> <BLANKS> <add_method>
		<method> <BLANKS> <set_method> <BLANKS> <get_method>
		...
		<method> <BLANKS> <set_method> <BLANKS> <get_method>
		/ / /
		<subs_from> <BLANKS> <subs_to>
		...
		<subs_from> <BLANKS> <subs_to>
		/ /

