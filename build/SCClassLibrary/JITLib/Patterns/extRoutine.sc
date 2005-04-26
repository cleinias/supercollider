

+Pattern {
	lock { arg n=1;
		^Pfin(n.asStream, this.asStream)
	}
}


+Stream {
	
	fastForward { arg by, tolerance=0;
		var t=0, delta=0, event, scrub;
		if(by <= 0) { ^0.0 };
		while { t.roundUp(tolerance) < by } 
		{ 
			event = this.next(Event.default);
			if(event.isNil) { ("end of stream. Time left:" + (by - t)).inform; ^t - by };
			event = event.copy.put(\freq, \rest);
			delta = event.play;
			if(delta.isNil) { ("end of stream. Time left:" + (by - t)).inform; ^t - by };
			t = t + delta;

		};
		^t - by // time left to next event
	}
		
}


+ EventStreamPlayer {
	
	xplay { arg fadeTime, argClock, doReset = false, quant=1.0;
		if (doReset, { this.reset });
		clock = argClock ? clock ? TempoClock.default;
		stream = PfadeIn(originalStream, fadeTime).asStream;
		clock.play(this, quant);
	}
	xstop { arg fadeTime;
		stream = PfadeOut(stream, fadeTime).asStream;
	}


}
+PauseStream {

	xplay { arg fadeTime, argClock, doReset = false, quant=1.0;
		this.play(argClock, doReset, quant);
	}
	xstop { // stop after fade?
		this.stop;
	}
}

+TempoClock {
	timeToNextBeat { arg quant=0.0;
		^quant.nextTimeOnGrid(this) - this.beats
	}
}

