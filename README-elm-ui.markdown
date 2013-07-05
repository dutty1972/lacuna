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

## How to use?

### parameters
In the parameters, you can use "::NAME" to refer to a const abbreviation.

<hr>


> ### add object
> ```asm
var :+ object (parameters)
```
> > ```html
Evas_Object * <var> = <prefix>_<object>_add(<parameters>)
```
> > `<prefix>` can be either `elm` or `evas`.

Create a new object, with `parameters` as the parameters, and name it
as `var`.

`(parameters)`(with parentheses) can be omitted if no parameter.

#### Example

```asm
ok :+ button(win);
```

<hr>


> ### bind smart event
> ```asm
var :- event (func, func_data)
```
> > ```html
evas_object_smart_callback_add(<var>, <event>, <func>, <func_data>)
```

#### Example
```asm
ok :- clicked((void *)on_ok_clicked, NULL);
```

<hr>


> ### declare object
> ```asm
object :* var
```
> > ```html
Evas_Object * <var>
```

This will make the code clearer, and it helps to track the variable type
for `lpp-elm-ui`.

#### Example
```c
void on_ok_clicked(void * data, button :* btn)
{
	// do something with <btn>...
}
```

<hr>


> ### cast object type
> ```asm
var := object
```

It do *not* actually generate any code, but it change(cast) the type of
`<var>` into `<object>` so that `lpp-elm-ui` can use it as `<object>`.

It can also be used to declare `<var>` inside `lpp-elm-ui`, while
producing no code.

#### Example
``` asm
ok := evas.object;
```

<hr>


> ### get function
> ```asm
var :: func (parameters)
```
> > ```html
<realfunc>(<var>, <parameters>)
```
> > Please refer to `realfunc()` below for `<realfunc>`.

This is used for the function that people normally want to use its
return value, which is called the *get function*.

`(parameters)`(with parentheses) can be omitted if no parameter.

#### Example
```c
sl:=slider;
printf("%d\n", (int)sl::value);
```

<hr>


> ### set function
> ```asm
var : func (paramaters)
```
> > ```html
<realfunc>(<var>, <parameters>)
```
> > Please refer to `realfunc()` below for `<realfunc>`.

This is used for the function that people normally want to use its
for setting a value, which is called the *set function*.

`(parameters)`(with parentheses) can be omitted if no parameter.

#### Example
```c
sl:=slider;
sl: value(2.0);
```

<hr>


> ### realfunc()
> ```perl
sub &realfunc($type, $object, $func)
```
> > `$type` can be either `'g'` or `'s'`, means `Get function`
> > or `Set function`.

**NOTE**: This is an *implementation detail* rather than the code you
can use in your program.

This `sub` searches *database*(see below), and do the logic:

1. if `elm_${object}_${func}_${type}et` is found, return it
2. if `elm_${object}_${func}` is found, return it.
3. if `elm_object_${func}_${type}et` is found, return it
4. if `elm_object_${func}` is found, return it.
5. if `elm_anything_${func}_${type}et` is found, return it
6. if `elm_anything_${func}` is found, return it.
7. if `evas_${object}_${func}_${type}et` is found, return it
8. if `evas_${object}_${func}` is found, return it.
9. if `evas_object_${func}_${type}et` is found, return it
10. if `evas_object_${func}` is found, return it.
11. if `evas_anything_${func}_${type}et` is found, return it
12. if `evas_anything_${func}` is found, return it.
13. die

**NOTE**: `anything` in the code above really means **anything**!

#### database
database is really just a collection of function names existed in
elementary and evas header files! Just like this:

```asm
elm_bg_add
elm_bg_color_get
elm_bg_color_set
elm_bg_file_get
elm_bg_file_set
evas_object_focus_set
evas_object_freeze_events_get
evas_object_freeze_events_set
evas_object_geometry_get
```
(Of course it's not complete.)

