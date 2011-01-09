package fseq {

/**
 *	Class description.
 *
 *	@langversion ActionScript 3.0
 *	@playerversion Flash 10.0
 *
 *	@author Zach Archer
 *	@since  20110108
 */

import flash.display.*;
import flash.events.*;
import flash.geom.*;
import caurina.transitions.Tweener;
import com.zacharcher.color.*;
import com.zacharcher.math.*;

public class FormantSequence extends Object
{
	//--------------------------------------
	// CLASS CONSTANTS
	//--------------------------------------
	public static const FRAMES :int = 512;
	public static const VOICED_OPS :int = 8;
	public static const UNVOICED_OPS :int = 8;
	
	//--------------------------------------
	//  CONSTRUCTOR
	//--------------------------------------
	public function FormantSequence( inPitch:Operator=null, inVoiced:Vector.<Operator>=null, inUnvoiced:Vector.<Operator>=null ) {
		super();
		
		if( inPitch ) {
			_pitch = inPitch;
		} else {
			_pitch = new Operator();	// empty
		}
		
		if( inVoiced ) {
			_voiced = inVoiced;
		} else {
			_voiced = new Vector.<Operator>();
			for( var v:int=0; v<VOICED_OPS; v++ ) {
				_voiced.push( new Operator() );
			}
		}

		if( inUnoiced ) {
			_unvoiced = inUnvoiced;
		} else {
			_unvoiced = new Vector.<Operator>();
			for( var u:int=0; u<UNVOICED_OPS; u++ ) {
				_unvoiced.push( new Operator() );
			}
		}
	}
	
	//--------------------------------------
	//  PRIVATE VARIABLES
	//--------------------------------------
	private var _pitch :Operator;	// Disregards its own amplitude
	private var _voiced :Vector.<Operator>;
	private var _unvoiced :Vector.<Operator>;
	
	//--------------------------------------
	//  GETTER/SETTERS
	//--------------------------------------
	
	//--------------------------------------
	//  PUBLIC METHODS
	//--------------------------------------
	public function clone() :FormantSequence {
		// Duplicate the pitch
		var pitchClone:Operator = _pitch.clone();

		var o:int;
		
		// Duplicate the voiced operators
		var vClone:Vector.<Operator> = new Vector.<Operator>();
		for( o=0; o<VOICED_OPS; o++ ) {
			vClone.push( _voiced[o].clone() );
		}
		
		// Duplicate the unvoiced operators
		vor uClone:Vector.<Operator> = new Vector.<Operator>();
		for( o=0; o<UNVOICED_OPS; o++ ) {
			uClone.push( _unvoiced[o].clone() );
		}
		
		return new FormantSequence( pitchClone, vClone, uClone );
	}
	
	//--------------------------------------
	//  EVENT HANDLERS
	//--------------------------------------
	
	//--------------------------------------
	//  PRIVATE & PROTECTED INSTANCE METHODS
	//--------------------------------------
	
}

}

