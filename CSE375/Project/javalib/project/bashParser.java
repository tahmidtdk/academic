// Generated from bash.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class bashParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		PARRM=1, DASH=2, WORD=3, WOR_SLS=4, SEMICOLON=5, SPACE=6, NEWLINE=7;
	public static final int
		RULE_expression = 0, RULE_command = 1, RULE_peremeter = 2, RULE_string = 3, 
		RULE_path = 4, RULE_object = 5;
	public static final String[] ruleNames = {
		"expression", "command", "peremeter", "string", "path", "object"
	};

	private static final String[] _LITERAL_NAMES = {
		null, null, "'-'", null, null, "';'", "' '"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "PARRM", "DASH", "WORD", "WOR_SLS", "SEMICOLON", "SPACE", "NEWLINE"
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
	public String getGrammarFileName() { return "bash.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public bashParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class ExpressionContext extends ParserRuleContext {
		public List<CommandContext> command() {
			return getRuleContexts(CommandContext.class);
		}
		public CommandContext command(int i) {
			return getRuleContext(CommandContext.class,i);
		}
		public List<TerminalNode> SEMICOLON() { return getTokens(bashParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(bashParser.SEMICOLON, i);
		}
		public List<TerminalNode> NEWLINE() { return getTokens(bashParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(bashParser.NEWLINE, i);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).exitExpression(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(22);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==WORD) {
				{
				{
				setState(12);
				command();
				setState(13);
				match(SEMICOLON);
				setState(17);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEWLINE) {
					{
					{
					setState(14);
					match(NEWLINE);
					}
					}
					setState(19);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				}
				setState(24);
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

	public static class CommandContext extends ParserRuleContext {
		public TerminalNode WORD() { return getToken(bashParser.WORD, 0); }
		public PeremeterContext peremeter() {
			return getRuleContext(PeremeterContext.class,0);
		}
		public StringContext string() {
			return getRuleContext(StringContext.class,0);
		}
		public List<TerminalNode> SPACE() { return getTokens(bashParser.SPACE); }
		public TerminalNode SPACE(int i) {
			return getToken(bashParser.SPACE, i);
		}
		public CommandContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_command; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).enterCommand(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).exitCommand(this);
		}
	}

	public final CommandContext command() throws RecognitionException {
		CommandContext _localctx = new CommandContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_command);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(25);
			match(WORD);
			setState(29);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(26);
					match(SPACE);
					}
					} 
				}
				setState(31);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			setState(34);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PARRM:
				{
				setState(32);
				peremeter();
				}
				break;
			case WORD:
			case WOR_SLS:
			case SEMICOLON:
			case SPACE:
				{
				setState(33);
				string();
				}
				break;
			default:
				throw new NoViableAltException(this);
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

	public static class PeremeterContext extends ParserRuleContext {
		public TerminalNode PARRM() { return getToken(bashParser.PARRM, 0); }
		public PeremeterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_peremeter; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).enterPeremeter(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).exitPeremeter(this);
		}
	}

	public final PeremeterContext peremeter() throws RecognitionException {
		PeremeterContext _localctx = new PeremeterContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_peremeter);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(36);
			match(PARRM);
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

	public static class StringContext extends ParserRuleContext {
		public PathContext path() {
			return getRuleContext(PathContext.class,0);
		}
		public ObjectContext object() {
			return getRuleContext(ObjectContext.class,0);
		}
		public StringContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_string; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).enterString(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).exitString(this);
		}
	}

	public final StringContext string() throws RecognitionException {
		StringContext _localctx = new StringContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_string);
		try {
			setState(40);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(38);
				path();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(39);
				object();
				}
				break;
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

	public static class PathContext extends ParserRuleContext {
		public List<TerminalNode> WOR_SLS() { return getTokens(bashParser.WOR_SLS); }
		public TerminalNode WOR_SLS(int i) {
			return getToken(bashParser.WOR_SLS, i);
		}
		public List<TerminalNode> SPACE() { return getTokens(bashParser.SPACE); }
		public TerminalNode SPACE(int i) {
			return getToken(bashParser.SPACE, i);
		}
		public PathContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_path; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).enterPath(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).exitPath(this);
		}
	}

	public final PathContext path() throws RecognitionException {
		PathContext _localctx = new PathContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_path);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(51);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==WOR_SLS || _la==SPACE) {
				{
				{
				setState(45);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==SPACE) {
					{
					{
					setState(42);
					match(SPACE);
					}
					}
					setState(47);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				{
				setState(48);
				match(WOR_SLS);
				}
				}
				}
				setState(53);
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

	public static class ObjectContext extends ParserRuleContext {
		public List<TerminalNode> WORD() { return getTokens(bashParser.WORD); }
		public TerminalNode WORD(int i) {
			return getToken(bashParser.WORD, i);
		}
		public List<TerminalNode> SPACE() { return getTokens(bashParser.SPACE); }
		public TerminalNode SPACE(int i) {
			return getToken(bashParser.SPACE, i);
		}
		public ObjectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_object; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).enterObject(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof bashListener ) ((bashListener)listener).exitObject(this);
		}
	}

	public final ObjectContext object() throws RecognitionException {
		ObjectContext _localctx = new ObjectContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_object);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(63);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==WORD || _la==SPACE) {
				{
				{
				setState(57);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==SPACE) {
					{
					{
					setState(54);
					match(SPACE);
					}
					}
					setState(59);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				{
				setState(60);
				match(WORD);
				}
				}
				}
				setState(65);
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\tE\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\3\2\3\2\3\2\7\2\22\n\2\f\2\16\2\25"+
		"\13\2\7\2\27\n\2\f\2\16\2\32\13\2\3\3\3\3\7\3\36\n\3\f\3\16\3!\13\3\3"+
		"\3\3\3\5\3%\n\3\3\4\3\4\3\5\3\5\5\5+\n\5\3\6\7\6.\n\6\f\6\16\6\61\13\6"+
		"\3\6\7\6\64\n\6\f\6\16\6\67\13\6\3\7\7\7:\n\7\f\7\16\7=\13\7\3\7\7\7@"+
		"\n\7\f\7\16\7C\13\7\3\7\2\2\b\2\4\6\b\n\f\2\2\2G\2\30\3\2\2\2\4\33\3\2"+
		"\2\2\6&\3\2\2\2\b*\3\2\2\2\n\65\3\2\2\2\fA\3\2\2\2\16\17\5\4\3\2\17\23"+
		"\7\7\2\2\20\22\7\t\2\2\21\20\3\2\2\2\22\25\3\2\2\2\23\21\3\2\2\2\23\24"+
		"\3\2\2\2\24\27\3\2\2\2\25\23\3\2\2\2\26\16\3\2\2\2\27\32\3\2\2\2\30\26"+
		"\3\2\2\2\30\31\3\2\2\2\31\3\3\2\2\2\32\30\3\2\2\2\33\37\7\5\2\2\34\36"+
		"\7\b\2\2\35\34\3\2\2\2\36!\3\2\2\2\37\35\3\2\2\2\37 \3\2\2\2 $\3\2\2\2"+
		"!\37\3\2\2\2\"%\5\6\4\2#%\5\b\5\2$\"\3\2\2\2$#\3\2\2\2%\5\3\2\2\2&\'\7"+
		"\3\2\2\'\7\3\2\2\2(+\5\n\6\2)+\5\f\7\2*(\3\2\2\2*)\3\2\2\2+\t\3\2\2\2"+
		",.\7\b\2\2-,\3\2\2\2.\61\3\2\2\2/-\3\2\2\2/\60\3\2\2\2\60\62\3\2\2\2\61"+
		"/\3\2\2\2\62\64\7\6\2\2\63/\3\2\2\2\64\67\3\2\2\2\65\63\3\2\2\2\65\66"+
		"\3\2\2\2\66\13\3\2\2\2\67\65\3\2\2\28:\7\b\2\298\3\2\2\2:=\3\2\2\2;9\3"+
		"\2\2\2;<\3\2\2\2<>\3\2\2\2=;\3\2\2\2>@\7\5\2\2?;\3\2\2\2@C\3\2\2\2A?\3"+
		"\2\2\2AB\3\2\2\2B\r\3\2\2\2CA\3\2\2\2\13\23\30\37$*/\65;A";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}