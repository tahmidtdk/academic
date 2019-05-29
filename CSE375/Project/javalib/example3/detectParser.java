// Generated from detect.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class detectParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, ID=8, NEWLINE=9;
	public static final int
		RULE_student = 0, RULE_start = 1, RULE_year = 2, RULE_semester = 3, RULE_summer = 4, 
		RULE_spring = 5, RULE_fall = 6, RULE_department = 7, RULE_cse = 8, RULE_bba = 9, 
		RULE_pharmacy = 10, RULE_seperator = 11, RULE_id = 12;
	public static final String[] ruleNames = {
		"student", "start", "year", "semester", "summer", "spring", "fall", "department", 
		"cse", "bba", "pharmacy", "seperator", "id"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'2'", "'1'", "'3'", "'60'", "'10'", "'70'", "'-'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, null, null, "ID", "NEWLINE"
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
	public String getGrammarFileName() { return "detect.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public detectParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class StudentContext extends ParserRuleContext {
		public List<StartContext> start() {
			return getRuleContexts(StartContext.class);
		}
		public StartContext start(int i) {
			return getRuleContext(StartContext.class,i);
		}
		public List<TerminalNode> NEWLINE() { return getTokens(detectParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(detectParser.NEWLINE, i);
		}
		public StudentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_student; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterStudent(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitStudent(this);
		}
	}

	public final StudentContext student() throws RecognitionException {
		StudentContext _localctx = new StudentContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_student);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(31);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==ID) {
				{
				{
				setState(26);
				start();
				setState(27);
				match(NEWLINE);
				}
				}
				setState(33);
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

	public static class StartContext extends ParserRuleContext {
		public YearContext year() {
			return getRuleContext(YearContext.class,0);
		}
		public List<SeperatorContext> seperator() {
			return getRuleContexts(SeperatorContext.class);
		}
		public SeperatorContext seperator(int i) {
			return getRuleContext(SeperatorContext.class,i);
		}
		public SemesterContext semester() {
			return getRuleContext(SemesterContext.class,0);
		}
		public DepartmentContext department() {
			return getRuleContext(DepartmentContext.class,0);
		}
		public IdContext id() {
			return getRuleContext(IdContext.class,0);
		}
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterStart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitStart(this);
		}
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(34);
			year();
			setState(35);
			seperator();
			setState(36);
			semester();
			setState(37);
			seperator();
			setState(38);
			department();
			setState(39);
			seperator();
			setState(40);
			id();
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

	public static class YearContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(detectParser.ID, 0); }
		public YearContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_year; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterYear(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitYear(this);
		}
	}

	public final YearContext year() throws RecognitionException {
		YearContext _localctx = new YearContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_year);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(42);
			match(ID);
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

	public static class SemesterContext extends ParserRuleContext {
		public SummerContext summer() {
			return getRuleContext(SummerContext.class,0);
		}
		public SpringContext spring() {
			return getRuleContext(SpringContext.class,0);
		}
		public FallContext fall() {
			return getRuleContext(FallContext.class,0);
		}
		public SemesterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_semester; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterSemester(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitSemester(this);
		}
	}

	public final SemesterContext semester() throws RecognitionException {
		SemesterContext _localctx = new SemesterContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_semester);
		try {
			setState(47);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
				enterOuterAlt(_localctx, 1);
				{
				setState(44);
				summer();
				}
				break;
			case T__1:
				enterOuterAlt(_localctx, 2);
				{
				setState(45);
				spring();
				}
				break;
			case T__2:
				enterOuterAlt(_localctx, 3);
				{
				setState(46);
				fall();
				}
				break;
			default:
				throw new NoViableAltException(this);
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

	public static class SummerContext extends ParserRuleContext {
		public SummerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_summer; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterSummer(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitSummer(this);
		}
	}

	public final SummerContext summer() throws RecognitionException {
		SummerContext _localctx = new SummerContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_summer);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(49);
			match(T__0);
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

	public static class SpringContext extends ParserRuleContext {
		public SpringContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_spring; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterSpring(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitSpring(this);
		}
	}

	public final SpringContext spring() throws RecognitionException {
		SpringContext _localctx = new SpringContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_spring);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(51);
			match(T__1);
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

	public static class FallContext extends ParserRuleContext {
		public FallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fall; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterFall(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitFall(this);
		}
	}

	public final FallContext fall() throws RecognitionException {
		FallContext _localctx = new FallContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_fall);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(53);
			match(T__2);
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

	public static class DepartmentContext extends ParserRuleContext {
		public CseContext cse() {
			return getRuleContext(CseContext.class,0);
		}
		public BbaContext bba() {
			return getRuleContext(BbaContext.class,0);
		}
		public PharmacyContext pharmacy() {
			return getRuleContext(PharmacyContext.class,0);
		}
		public DepartmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_department; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterDepartment(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitDepartment(this);
		}
	}

	public final DepartmentContext department() throws RecognitionException {
		DepartmentContext _localctx = new DepartmentContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_department);
		try {
			setState(58);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__3:
				enterOuterAlt(_localctx, 1);
				{
				setState(55);
				cse();
				}
				break;
			case T__4:
				enterOuterAlt(_localctx, 2);
				{
				setState(56);
				bba();
				}
				break;
			case T__5:
				enterOuterAlt(_localctx, 3);
				{
				setState(57);
				pharmacy();
				}
				break;
			default:
				throw new NoViableAltException(this);
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

	public static class CseContext extends ParserRuleContext {
		public CseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_cse; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterCse(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitCse(this);
		}
	}

	public final CseContext cse() throws RecognitionException {
		CseContext _localctx = new CseContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_cse);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(60);
			match(T__3);
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

	public static class BbaContext extends ParserRuleContext {
		public BbaContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_bba; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterBba(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitBba(this);
		}
	}

	public final BbaContext bba() throws RecognitionException {
		BbaContext _localctx = new BbaContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_bba);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(62);
			match(T__4);
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

	public static class PharmacyContext extends ParserRuleContext {
		public PharmacyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pharmacy; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterPharmacy(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitPharmacy(this);
		}
	}

	public final PharmacyContext pharmacy() throws RecognitionException {
		PharmacyContext _localctx = new PharmacyContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_pharmacy);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(64);
			match(T__5);
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

	public static class SeperatorContext extends ParserRuleContext {
		public SeperatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_seperator; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterSeperator(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitSeperator(this);
		}
	}

	public final SeperatorContext seperator() throws RecognitionException {
		SeperatorContext _localctx = new SeperatorContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_seperator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(66);
			match(T__6);
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
		public TerminalNode ID() { return getToken(detectParser.ID, 0); }
		public IdContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_id; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).enterId(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof detectListener ) ((detectListener)listener).exitId(this);
		}
	}

	public final IdContext id() throws RecognitionException {
		IdContext _localctx = new IdContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_id);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			match(ID);
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\13I\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\4"+
		"\f\t\f\4\r\t\r\4\16\t\16\3\2\3\2\3\2\7\2 \n\2\f\2\16\2#\13\2\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\5\3\5\3\5\5\5\62\n\5\3\6\3\6\3\7\3\7"+
		"\3\b\3\b\3\t\3\t\3\t\5\t=\n\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3"+
		"\16\3\16\2\2\17\2\4\6\b\n\f\16\20\22\24\26\30\32\2\2\2@\2!\3\2\2\2\4$"+
		"\3\2\2\2\6,\3\2\2\2\b\61\3\2\2\2\n\63\3\2\2\2\f\65\3\2\2\2\16\67\3\2\2"+
		"\2\20<\3\2\2\2\22>\3\2\2\2\24@\3\2\2\2\26B\3\2\2\2\30D\3\2\2\2\32F\3\2"+
		"\2\2\34\35\5\4\3\2\35\36\7\13\2\2\36 \3\2\2\2\37\34\3\2\2\2 #\3\2\2\2"+
		"!\37\3\2\2\2!\"\3\2\2\2\"\3\3\2\2\2#!\3\2\2\2$%\5\6\4\2%&\5\30\r\2&\'"+
		"\5\b\5\2\'(\5\30\r\2()\5\20\t\2)*\5\30\r\2*+\5\32\16\2+\5\3\2\2\2,-\7"+
		"\n\2\2-\7\3\2\2\2.\62\5\n\6\2/\62\5\f\7\2\60\62\5\16\b\2\61.\3\2\2\2\61"+
		"/\3\2\2\2\61\60\3\2\2\2\62\t\3\2\2\2\63\64\7\3\2\2\64\13\3\2\2\2\65\66"+
		"\7\4\2\2\66\r\3\2\2\2\678\7\5\2\28\17\3\2\2\29=\5\22\n\2:=\5\24\13\2;"+
		"=\5\26\f\2<9\3\2\2\2<:\3\2\2\2<;\3\2\2\2=\21\3\2\2\2>?\7\6\2\2?\23\3\2"+
		"\2\2@A\7\7\2\2A\25\3\2\2\2BC\7\b\2\2C\27\3\2\2\2DE\7\t\2\2E\31\3\2\2\2"+
		"FG\7\n\2\2G\33\3\2\2\2\5!\61<";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}