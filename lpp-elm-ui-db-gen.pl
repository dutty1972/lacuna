#!/usr/bin/perl

my @ds = map {
	my $d = $_;
	if ($d =~ s/^-I//) { $d }
	else { undef }
} split /\s+/, `pkg-config --cflags elementary`;

my @db;
for (@ds) {
	print;
	print" -> ";
	/([a-z_]+)-[0-9]+$/ or next;
	my $prefix = $1;
	print "$prefix\n";
	for (<$_/*.h>) {
		open $F, '<', $_;
		while (<$F>) { /[^_]((elm|evas)_[^()]+)\(.*/g and unshift @db, $1 }
		close $F;
	}
}

print(join("\n", sort(@db)));

