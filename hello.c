#if 0
./lpp elm-ui $0 -o hello `(pkg-config --cflags --libs elementary)` &&
		./hello
rm -f hello
exit 0
#endif

// you can run this by:
// 		sh hello.c

#include <Elementary.h>
#include <stdio.h>


// only below is parsed by elm-ui
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

label :* text;		// global variable

EAPI_MAIN int elm_main(int argc, char * argv[])
{
	win:+win			(NULL, "test-elm", ELM_WIN_BASIC);
	win: title			("Test Elementary");
	win: resize			(200, 100);
	win:-delete,request	((void *)elm_exit, NULL);

	bg :+bg				(win);
	bg : size_hint_weight(EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	win: resize_object_add(bg);
	bg : show;

	vbox:+box			(win);
	vbox: size_hint_weight(EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	win : resize_object_add(vbox);
	vbox: show;

	{
		__:+label		(win);
		text = __;
	}
	text: text		("Hello, World!");
	text: scale		(2.0);
	text: size_hint_weight(0, EVAS_HINT_EXPAND);
	text: size_hint_align(0.5, EVAS_HINT_FILL);
	vbox: pack_end	(text);
	text: show;

	btn :+button	(win);
	btn : text		("Click Me!");
	btn : size_hint_weight(0, 0.5);
	vbox: pack_end	(btn);
	btn : show;

	void on_btn_clicked(const char * str, button :* btn)
	{
		text: text	(str);
		btn : hide;
	}
	btn :-clicked	((void *)on_btn_clicked, "Yes! Yes! Yes!!!");

	win: show;

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// only above is parsed by elm-ui

	elm_run();
	elm_shutdown();
	return 0;
}
ELM_MAIN()
// vim: noet ts=4 sw=4 sts=0 ft=c

