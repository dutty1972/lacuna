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

	evas object
		weight
			size_hint_weight_set
			size_hint_weight_get
			EXPAND	EVAS_HINT_EXPAND

		align
			size_hint_align_set
			size_hint_align_get
			FILL	EVAS_HINT_FILL


	elm table
		pack
			pack
			/


	elm box
		pack
			pack_end
			/

		pack_end
			pack_end
			/
		
		

In the configuration file, blank lines is very important.
They tell the parser when a section ends.

	prefix object_type
		method
			set_func
			get_func
			what_to_replace <BLANKS> replacement
			what_to_replace <BLANKS> replacement
			what_to_replace <BLANKS> replacement
			what_to_replace <BLANKS> replacement
			...
		<BLANK_LINE>
		method
			set_func
			get_func
			what_to_replace <BLANKS> replacement
		<BLANK_LINE>
		method
			set_func
			get_func
			what_to_replace <BLANKS> replacement
		<BLANK_LINE>
		method
			set_func
			get_func
			what_to_replace <BLANKS> replacement
		<BLANK_LINE>
		...
	<BLANK_LINE>
	prefix object_type
		method
			set_func
			get_func
			what_to_replace <BLANKS> replacement
		<BLANK_LINE>
	<BLANK_LINE>
	...



