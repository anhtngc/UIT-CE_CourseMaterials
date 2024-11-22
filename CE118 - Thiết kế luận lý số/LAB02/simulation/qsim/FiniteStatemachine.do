onerror {quit -f}
vlib work
vlog -work work FiniteStatemachine.vo
vlog -work work FiniteStatemachine.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.Mealy-type_vlg_vec_tst
vcd file -direction FiniteStatemachine.msim.vcd
vcd add -internal Mealy-type_vlg_vec_tst/*
vcd add -internal Mealy-type_vlg_vec_tst/i1/*
add wave /*
run -all
