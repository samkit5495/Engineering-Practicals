set val(chan)          Channel/WirelessChannel      ;# channel type
set val(prop)          Propagation/TwoRayGround     ;# radio-propagation model
set val(netif)         Phy/WirelessPhy     ;# network interface type
set val(mac)           Mac/802_11              ;# MAC type
set val(ifq)           Queue/DropTail/PriQueue      ;# interface queue type
set val(ll)            LL                           ;# link layer type
set val(ant)           Antenna/OmniAntenna          ;# antenna model
set val(ifqlen)        100	         	    ;# max packet in ifq
set val(nn)            20			    ;# number of mobilenodes
set val(rp)            AODV			    ;# protocol tye
set val(x)             50			    ;# X dimension of topography
set val(y)             50			    ;# Y dimension of topography
set val(stop)          500			    ;# simulation period 
set val(energymodel)   EnergyModel		    ;# Energy Model
set val(initialenergy) 100			    ;# value

set ns        		[new Simulator]
set tracefd       	[open sim_802_11.tr w]
set namtrace      	[open sim_802_11.nam w]

$ns use-newtrace
$ns trace-all $tracefd
$ns namtrace-all-wireless $namtrace $val(x) $val(y)


# set up topography object
set topo       [new Topography]
$topo load_flatgrid $val(x) $val(y)

create-god $val(nn)

# configure the nodes
$ns node-config -adhocRouting $val(rp) \
            -llType $val(ll) \
             -macType $val(mac) \
             -ifqType $val(ifq) \
             -ifqLen $val(ifqlen) \
             -antType $val(ant) \
             -propType $val(prop) \
             -phyType $val(netif) \
             -channel [new $val(chan)] \
             -topoInstance $topo \
             -agentTrace OFF \
             -routerTrace OFF \
             -macTrace  ON \
             -movementTrace OFF \
             -energyModel $val(energymodel) \
             -initialEnergy $val(initialenergy) \
             -rxPower 35.28e-3 \
             -txPower 31.32e-3 \
	     -idlePower 712e-6 \
	     -sleepPower 144e-9 
                           
             
for {set i 0} {$i < $val(nn) } { incr i } {
        set mnode_($i) [$ns node]
}



for {set i 1} {$i < $val(nn) } { incr i } {
	$mnode_($i) set X_ [ expr {$val(x) * rand()} ]
	$mnode_($i) set Y_ [ expr {$val(y) * rand()} ]
	$mnode_($i) set Z_ 0
}

# Position of Sink
$mnode_(0) set X_ [ expr {$val(x)/2} ]
$mnode_(0) set Y_ [ expr {$val(y)/2} ]
$mnode_(0) set Z_ 0.0
$mnode_(0) label "Sink"


for {set i 0} {$i < $val(nn)} { incr i } {
	$ns initial_node_pos $mnode_($i) 10
}


#Setup a UDP connection
for {set i 1} {$i < $val(nn) } { incr i } {
set udp($i) [new Agent/UDP]
$ns attach-agent $mnode_($i) $udp($i)
}


set sink [new Agent/Null]
$ns attach-agent $mnode_(0) $sink

for {set i 1} {$i < $val(nn) } { incr i } {
$ns connect $udp($i) $sink
}

#Setup a CBR over UDP connection

for {set i 1} {$i < $val(nn) } { incr i } {
set cbr($i) [new Application/Traffic/CBR]
$cbr($i) attach-agent $udp($i)
$cbr($i) set type_ CBR
$cbr($i) set packet_size_ 100
$cbr($i) set maxpkts_ 100
#$cbr($i) set rate_ 0.1Mb
$cbr($i) set interval_ 1
$cbr($i) set random_ false
}
for {set i 1} {$i < $val(nn) } { incr i } {
$ns at [expr {$i + 5}] "$cbr($i) start"
}



for {set i 1} {$i < $val(nn) } { incr i } {
$ns at [expr $val(stop) - $i] "$cbr($i) stop"
}
# Telling nodes when the simulation ends
for {set i 0} {$i < $val(nn) } { incr i } {
    $ns at $val(stop) "$mnode_($i) reset;"
}

# ending nam and the simulation
$ns at $val(stop) "$ns nam-end-wireless $val(stop)"
$ns at $val(stop) "stop"
$ns at [expr $val(stop) + 0.01] "puts \"end simulation\"; $ns halt"
proc stop {} {
    global ns tracefd namtrace
    $ns flush-trace
    close $tracefd
    close $namtrace
}

$ns run


