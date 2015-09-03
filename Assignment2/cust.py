from mininet.topo import Topo;
import sys;
import mininet;
from mininet.node import Controller;
from mininet.log import setLogLevel;
from mininet.net import Mininet;
from mininet.link import TCLink
from mininet.cli import CLI;


def MyTopo( self , a, b):
	
	
	a = int(a);
	b = int(b);
	switches = [];
	#hosts = [];
	for i in range(1, b+1):
		swi = self.addSwitch('s'+str(i));
		switches.append(swi);
	
	for i in range(len(switches)-1):
		self.addLink( switches[i],switches[(i+1)%len(switches)] );
	
	for i in range(1, a*b+1):
		host = 1;
		if i%2 == 1:
			host = self.addHost('h'+str(i), ip = '9.0.0.'+str(i));
		else:
			host = self.addHost('h'+str(i), ip='10.0.0.'+str(i));
		switch_no = (i-1)/a;
		link = self.addLink(switches[switch_no], host);
		if i%2 == 1:
			link.intf1.config(bw=1);
		else:
			link.intf1.config(bw=2);			
		
	#print "done"
	#leftHost = self.addHost('h1');
	#rightHost = self.addHost('h2');
	#lSwitch = self.addSwitch('s1');
	
	#self.addLink(leftHost, lSwitch);
	#self.addLink(lSwitch, rightHost);


x = sys.argv;
#print x;
#if len(x) < 3:
#	print "Not enough arguments! Format: X hosts/switch, Y switches";
#	exit();

#build = MyTopo(x[1], x[2]);
#x = int(raw_input());
#y=int(raw_input());
#topos ={'mytopo': MyTopo(x[1],x[2] )};

if __name__ == '__main__':
	setLogLevel('info');
	#topos = {'mytopo' : (lambda : MyTopo(x, y))};
	net = Mininet(controller = Controller, link = TCLink);
	net.addController('c0');
	MyTopo(net, x[1], x[2]);
	#net.buildFromTopo(topos['mytopo']);
	net.start();
	CLI( net );
	net.stop();

	


