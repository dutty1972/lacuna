#if 0
./lpp elm-ui $0 -o hello `(pkg-config --cflags --libs elementary)` &&
		./hello
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
	win:+win			("test-elm", "test-elm");
	win: resize			(200, 100);
	win:-delete,request	((void *)elm_exit, NULL);

	vbox:+box			(win);
	vbox: weight		(EXPAND, EXPAND);
	win : resize_object	(vbox);
	vbox: show;

	text:+label		(win);
	text: scale		(2.0);
	text: weight	(0, EXPAND);
	text: align		(0.5, FILL);
	vbox: pack		(text);
	text: show;
	elm_object_text_set(text, "Hello, World!");	// unable to do this

	btn :+button	(win);
	btn : weight	(0, 0.5);
	vbox: pack		(btn);
	btn : show;
	elm_object_text_set(btn, "Click Me!");	// unable to do this

	void on_btn_clicked(const char * str, button :* btn)
	{
		elm_object_text_set(text, str);	// unable to do this
		btn: hide;
	}
	btn :-clicked	((void *)on_btn_clicked, "Yes! Yes! Yes!!!");

	win:show;

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// only above is parsed by elm-ui

	elm_run();
	elm_shutdown();
	return 0;
}
ELM_MAIN()
// vim: noet ts=4 sw=4 sts=0 ft=c

