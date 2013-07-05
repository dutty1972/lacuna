#!/usr/bin/perl

my @ds = map {
	undef;
	$1 if /^-I(.*(elementary|evas).*)$/;
} split /\s+/, `pkg-config --cflags elementary`;

my @funcs;
#my @consts;
for (@ds) {
	for (<$_/*.h>) {
		open my $F, '<', $_ or die $!;
		while (<$F>) {
			/EAPI.*((elm|evas)_[^()\s]+)\s*\(.*/ and unshift @funcs, $1;
			
			# TODO: substitute for consts
			# /#define\s+((ELM|EVAS)_[A-Z0-9_]+)/ and unshift @consts, $1;
		}
		close $F;
	}
}


open my $F, '> lpp-elm-ui.func.db' or die $!;
print $F join("\n", @funcs);
close $F;

