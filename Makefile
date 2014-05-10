all:
	make -C test_speed
	make -C test_fixed
	make -C test_ints

clean:
	make -C test_speed clean
	make -C test_fixed clean
	make -C test_ints clean

doc:
	cd spuc && doxygen >dox.log
