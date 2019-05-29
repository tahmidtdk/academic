// Generated from Super_Shop.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class Super_ShopParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, NUMBER=5, WORD=6, SPACE=7, NEWLINE=8;
	public static final int
		RULE_shop_info = 0, RULE_contact_number = 1, RULE_product = 2, RULE_price = 3, 
		RULE_name = 4, RULE_id = 5, RULE_location = 6;
	public static final String[] ruleNames = {
		"shop_info", "contact_number", "product", "price", "name", "id", "location"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'('", "')'", "'-'", "','", null, null, "' '"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, "NUMBER", "WORD", "SPACE", "NEWLINE"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Super_Shop.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public Super_ShopParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class Shop_infoContext extends ParserRuleContext {
		public List<LocationContext> location() {
			return getRuleContexts(LocationContext.class);
		}
		public LocationContext location(int i) {
			return getRuleContext(LocationContext.class,i);
		}
		public List<ProductContext> product() {
			return getRuleContexts(ProductContext.class);
		}
		public ProductContext product(int i) {
			return getRuleContext(ProductContext.class,i);
		}
		public List<Contact_numberContext> contact_number() {
			return getRuleContexts(Contact_numberContext.class);
		}
		public Contact_numberContext contact_number(int i) {
			return getRuleContext(Contact_numberContext.class,i);
		}
		public List<TerminalNode> NEWLINE() { return getTokens(Super_ShopParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(Super_ShopParser.NEWLINE, i);
		}
		public Shop_infoContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_shop_info; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).enterShop_info(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).exitShop_info(this);
		}
	}

	public final Shop_infoContext shop_info() throws RecognitionException {
		Shop_infoContext _localctx = new Shop_infoContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_shop_info);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(29);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0 || _la==WORD) {
				{
				{
				setState(14);
				location();
				setState(15);
				match(T__0);
				setState(16);
				product();
				setState(17);
				match(T__1);
				setState(18);
				match(T__0);
				setState(19);
				contact_number();
				setState(20);
				match(T__1);
				setState(24);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(21);
					match(NEWLINE);
					}
					}
					setState(26);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				}
				setState(31);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Contact_numberContext extends ParserRuleContext {
		public TerminalNode NUMBER() { return getToken(Super_ShopParser.NUMBER, 0); }
		public List<TerminalNode> SPACE() { return getTokens(Super_ShopParser.SPACE); }
		public TerminalNode SPACE(int i) {
			return getToken(Super_ShopParser.SPACE, i);
		}
		public Contact_numberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_contact_number; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).enterContact_number(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).exitContact_number(this);
		}
	}

	public final Contact_numberContext contact_number() throws RecognitionException {
		Contact_numberContext _localctx = new Contact_numberContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_contact_number);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(35);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SPACE) {
				{
				{
				setState(32);
				match(SPACE);
				}
				}
				setState(37);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(38);
			match(NUMBER);
			setState(42);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SPACE) {
				{
				{
				setState(39);
				match(SPACE);
				}
				}
				setState(44);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProductContext extends ParserRuleContext {
		public NameContext name() {
			return getRuleContext(NameContext.class,0);
		}
		public IdContext id() {
			return getRuleContext(IdContext.class,0);
		}
		public PriceContext price() {
			return getRuleContext(PriceContext.class,0);
		}
		public List<TerminalNode> SPACE() { return getTokens(Super_ShopParser.SPACE); }
		public TerminalNode SPACE(int i) {
			return getToken(Super_ShopParser.SPACE, i);
		}
		public ProductContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_product; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).enterProduct(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).exitProduct(this);
		}
	}

	public final ProductContext product() throws RecognitionException {
		ProductContext _localctx = new ProductContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_product);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(48);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SPACE) {
				{
				{
				setState(45);
				match(SPACE);
				}
				}
				setState(50);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(51);
			name();
			setState(55);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SPACE) {
				{
				{
				setState(52);
				match(SPACE);
				}
				}
				setState(57);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(58);
			id();
			setState(62);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SPACE) {
				{
				{
				setState(59);
				match(SPACE);
				}
				}
				setState(64);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(65);
			price();
			setState(69);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SPACE) {
				{
				{
				setState(66);
				match(SPACE);
				}
				}
				setState(71);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PriceContext extends ParserRuleContext {
		public TerminalNode NUMBER() { return getToken(Super_ShopParser.NUMBER, 0); }
		public PriceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_price; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).enterPrice(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).exitPrice(this);
		}
	}

	public final PriceContext price() throws RecognitionException {
		PriceContext _localctx = new PriceContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_price);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(72);
			match(NUMBER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NameContext extends ParserRuleContext {
		public TerminalNode WORD() { return getToken(Super_ShopParser.WORD, 0); }
		public List<TerminalNode> SPACE() { return getTokens(Super_ShopParser.SPACE); }
		public TerminalNode SPACE(int i) {
			return getToken(Super_ShopParser.SPACE, i);
		}
		public NameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_name; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).enterName(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).exitName(this);
		}
	}

	public final NameContext name() throws RecognitionException {
		NameContext _localctx = new NameContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_name);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(74);
			match(WORD);
			setState(78);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(75);
					match(SPACE);
					}
					} 
				}
				setState(80);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			}
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdContext extends ParserRuleContext {
		public TerminalNode WORD() { return getToken(Super_ShopParser.WORD, 0); }
		public TerminalNode NUMBER() { return getToken(Super_ShopParser.NUMBER, 0); }
		public List<TerminalNode> SPACE() { return getTokens(Super_ShopParser.SPACE); }
		public TerminalNode SPACE(int i) {
			return getToken(Super_ShopParser.SPACE, i);
		}
		public IdContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_id; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).enterId(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).exitId(this);
		}
	}

	public final IdContext id() throws RecognitionException {
		IdContext _localctx = new IdContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_id);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(81);
			match(WORD);
			setState(82);
			match(T__2);
			setState(83);
			match(NUMBER);
			setState(87);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(84);
					match(SPACE);
					}
					} 
				}
				setState(89);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			}
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LocationContext extends ParserRuleContext {
		public List<TerminalNode> WORD() { return getTokens(Super_ShopParser.WORD); }
		public TerminalNode WORD(int i) {
			return getToken(Super_ShopParser.WORD, i);
		}
		public List<TerminalNode> SPACE() { return getTokens(Super_ShopParser.SPACE); }
		public TerminalNode SPACE(int i) {
			return getToken(Super_ShopParser.SPACE, i);
		}
		public LocationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_location; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).enterLocation(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Super_ShopListener ) ((Super_ShopListener)listener).exitLocation(this);
		}
	}

	public final LocationContext location() throws RecognitionException {
		LocationContext _localctx = new LocationContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_location);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(108);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==WORD) {
				{
				{
				setState(90);
				match(WORD);
				setState(94);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(91);
						match(SPACE);
						}
						} 
					}
					setState(96);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				}
				setState(98);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__3) {
					{
					setState(97);
					match(T__3);
					}
				}

				setState(103);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==SPACE) {
					{
					{
					setState(100);
					match(SPACE);
					}
					}
					setState(105);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				}
				setState(110);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\nr\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\7\2\31\n\2\f\2\16\2\34\13\2\7\2\36\n\2\f\2\16\2!\13\2\3\3\7\3$\n"+
		"\3\f\3\16\3\'\13\3\3\3\3\3\7\3+\n\3\f\3\16\3.\13\3\3\4\7\4\61\n\4\f\4"+
		"\16\4\64\13\4\3\4\3\4\7\48\n\4\f\4\16\4;\13\4\3\4\3\4\7\4?\n\4\f\4\16"+
		"\4B\13\4\3\4\3\4\7\4F\n\4\f\4\16\4I\13\4\3\5\3\5\3\6\3\6\7\6O\n\6\f\6"+
		"\16\6R\13\6\3\7\3\7\3\7\3\7\7\7X\n\7\f\7\16\7[\13\7\3\b\3\b\7\b_\n\b\f"+
		"\b\16\bb\13\b\3\b\5\be\n\b\3\b\7\bh\n\b\f\b\16\bk\13\b\7\bm\n\b\f\b\16"+
		"\bp\13\b\3\b\2\2\t\2\4\6\b\n\f\16\2\2\2x\2\37\3\2\2\2\4%\3\2\2\2\6\62"+
		"\3\2\2\2\bJ\3\2\2\2\nL\3\2\2\2\fS\3\2\2\2\16n\3\2\2\2\20\21\5\16\b\2\21"+
		"\22\7\3\2\2\22\23\5\6\4\2\23\24\7\4\2\2\24\25\7\3\2\2\25\26\5\4\3\2\26"+
		"\32\7\4\2\2\27\31\7\n\2\2\30\27\3\2\2\2\31\34\3\2\2\2\32\30\3\2\2\2\32"+
		"\33\3\2\2\2\33\36\3\2\2\2\34\32\3\2\2\2\35\20\3\2\2\2\36!\3\2\2\2\37\35"+
		"\3\2\2\2\37 \3\2\2\2 \3\3\2\2\2!\37\3\2\2\2\"$\7\t\2\2#\"\3\2\2\2$\'\3"+
		"\2\2\2%#\3\2\2\2%&\3\2\2\2&(\3\2\2\2\'%\3\2\2\2(,\7\7\2\2)+\7\t\2\2*)"+
		"\3\2\2\2+.\3\2\2\2,*\3\2\2\2,-\3\2\2\2-\5\3\2\2\2.,\3\2\2\2/\61\7\t\2"+
		"\2\60/\3\2\2\2\61\64\3\2\2\2\62\60\3\2\2\2\62\63\3\2\2\2\63\65\3\2\2\2"+
		"\64\62\3\2\2\2\659\5\n\6\2\668\7\t\2\2\67\66\3\2\2\28;\3\2\2\29\67\3\2"+
		"\2\29:\3\2\2\2:<\3\2\2\2;9\3\2\2\2<@\5\f\7\2=?\7\t\2\2>=\3\2\2\2?B\3\2"+
		"\2\2@>\3\2\2\2@A\3\2\2\2AC\3\2\2\2B@\3\2\2\2CG\5\b\5\2DF\7\t\2\2ED\3\2"+
		"\2\2FI\3\2\2\2GE\3\2\2\2GH\3\2\2\2H\7\3\2\2\2IG\3\2\2\2JK\7\7\2\2K\t\3"+
		"\2\2\2LP\7\b\2\2MO\7\t\2\2NM\3\2\2\2OR\3\2\2\2PN\3\2\2\2PQ\3\2\2\2Q\13"+
		"\3\2\2\2RP\3\2\2\2ST\7\b\2\2TU\7\5\2\2UY\7\7\2\2VX\7\t\2\2WV\3\2\2\2X"+
		"[\3\2\2\2YW\3\2\2\2YZ\3\2\2\2Z\r\3\2\2\2[Y\3\2\2\2\\`\7\b\2\2]_\7\t\2"+
		"\2^]\3\2\2\2_b\3\2\2\2`^\3\2\2\2`a\3\2\2\2ad\3\2\2\2b`\3\2\2\2ce\7\6\2"+
		"\2dc\3\2\2\2de\3\2\2\2ei\3\2\2\2fh\7\t\2\2gf\3\2\2\2hk\3\2\2\2ig\3\2\2"+
		"\2ij\3\2\2\2jm\3\2\2\2ki\3\2\2\2l\\\3\2\2\2mp\3\2\2\2nl\3\2\2\2no\3\2"+
		"\2\2o\17\3\2\2\2pn\3\2\2\2\20\32\37%,\629@GPY`din";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}