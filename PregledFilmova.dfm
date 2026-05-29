object FormSviFilmovi: TFormSviFilmovi
  Left = 0
  Top = 0
  Caption = 'MySQL'
  ClientHeight = 1000
  ClientWidth = 1254
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label6: TLabel
    Left = 796
    Top = 147
    Width = 62
    Height = 15
    Caption = 'Naziv filma:'
  end
  object Label7: TLabel
    Left = 817
    Top = 176
    Width = 41
    Height = 15
    Caption = 'Godina:'
  end
  object Label8: TLabel
    Left = 814
    Top = 213
    Width = 44
    Height = 15
    Caption = 'Trajanje:'
  end
  object Label9: TLabel
    Left = 831
    Top = 239
    Width = 27
    Height = 15
    Caption = 'Opis:'
  end
  object Label1: TLabel
    Left = 24
    Top = 480
    Width = 3
    Height = 15
  end
  object LabelOmiljeniFilmoviNaslov: TLabel
    Left = 8
    Top = 16
    Width = 87
    Height = 15
    Caption = 'Omiljeni FIlmovi'
  end
  object LabelListaZaGledanje: TLabel
    Left = 8
    Top = 16
    Width = 86
    Height = 15
    Caption = 'Lista za gledanje'
  end
  object LabelFilm: TLabel
    Left = 8
    Top = 521
    Width = 26
    Height = 15
    Caption = 'Film:'
  end
  object LabelPoster: TLabel
    Left = 1160
    Top = 521
    Width = 36
    Height = 15
    Caption = 'Poster:'
  end
  object LabelUkupnoFilmova: TLabel
    Left = 740
    Top = 521
    Width = 3
    Height = 15
  end
  object ButtonDodajWatchlistu: TButton
    Left = 1104
    Top = 368
    Width = 145
    Height = 57
    Caption = 'Dodaj u Listu'
    TabOrder = 0
    OnClick = ButtonDodajWatchlistuClick
  end
  object EditNoviNaziv: TEdit
    Left = 880
    Top = 144
    Width = 177
    Height = 23
    TabOrder = 1
  end
  object EditNovaGodina: TEdit
    Left = 880
    Top = 173
    Width = 177
    Height = 23
    TabOrder = 2
  end
  object ButtonOmiljeniFilmovi: TButton
    Left = 1099
    Top = 144
    Width = 145
    Height = 57
    Caption = 'Omiljeni Filmovi'
    TabOrder = 3
    OnClick = ButtonOmiljeniFilmoviClick
  end
  object listViewOFilmovi: TListView
    Left = 0
    Top = 54
    Width = 790
    Height = 433
    Columns = <
      item
        Caption = 'Naziv filma'
      end
      item
        Caption = 'Godina'
      end
      item
        Caption = 'Trajanje'
      end
      item
        Caption = 'Opis'
      end>
    HideSelection = False
    TabOrder = 4
    ViewStyle = vsReport
    OnSelectItem = listViewOFilmoviSelectItem
  end
  object ButtonHRV: TButton
    Left = 1110
    Top = 8
    Width = 134
    Height = 34
    Caption = 'Hrvatski'
    TabOrder = 5
    OnClick = ButtonHRVClick
  end
  object ButtonENG: TButton
    Left = 1110
    Top = 48
    Width = 134
    Height = 34
    Caption = 'English'
    TabOrder = 6
    OnClick = ButtonENGClick
  end
  object ButtonDodajNoviOFilm: TButton
    Left = 880
    Top = 343
    Width = 177
    Height = 58
    Caption = 'Dodaj novi'
    TabOrder = 7
    OnClick = ButtonDodajNoviOFilmClick
  end
  object ButtonUkloni: TButton
    Left = 1099
    Top = 207
    Width = 145
    Height = 58
    Caption = 'Ukloni '
    TabOrder = 8
    OnClick = ButtonUkloniClick
  end
  object EditNovoTrajanje: TEdit
    Left = 880
    Top = 207
    Width = 177
    Height = 23
    TabOrder = 9
  end
  object MemoOpisNovogFilma: TMemo
    Left = 880
    Top = 236
    Width = 177
    Height = 93
    Lines.Strings = (
      'MemoOpisNovogFilma')
    TabOrder = 10
  end
  object ButtonPregledajListu: TButton
    Left = 1104
    Top = 431
    Width = 145
    Height = 56
    Caption = 'Pregledaj Listu'
    TabOrder = 11
    OnClick = ButtonPregledajListuClick
  end
  object ButtonRecenzije: TButton
    Left = 880
    Top = 436
    Width = 185
    Height = 45
    Caption = 'Recenzije'
    TabOrder = 12
  end
  object ButtonRESTBaza: TButton
    Left = 248
    Top = 512
    Width = 78
    Height = 41
    Caption = 'Dodaj u bazu'
    TabOrder = 13
    OnClick = ButtonRESTBazaClick
  end
  object editFilmRESTBaza: TEdit
    Left = 88
    Top = 518
    Width = 154
    Height = 23
    TabOrder = 14
    Text = 'editFilmRESTBaza'
  end
  object DBGridFilmoviBaza: TDBGrid
    Left = -12
    Top = 559
    Width = 885
    Height = 433
    DataSource = DataSourceFilm
    TabOrder = 15
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnCellClick = DBGridFilmoviBazaCellClick
  end
  object ToolBar1: TToolBar
    Left = 332
    Top = 512
    Width = 325
    Height = 41
    Align = alCustom
    ButtonHeight = 23
    ButtonWidth = 94
    Caption = 'ToolBar1'
    Customizable = True
    ShowCaptions = True
    TabOrder = 16
    object ToolButtonSQLSort: TToolButton
      Left = 0
      Top = 0
      Caption = 'Sortiraj'
      ImageIndex = 0
      OnClick = ToolButtonSQLSortClick
    end
    object ToolButtonSQLFilter: TToolButton
      Left = 94
      Top = 0
      Caption = 'Preporuka'
      ImageIndex = 1
      OnClick = ToolButtonSQLFilterClick
    end
    object ToolButtonSviPosteri: TToolButton
      Left = 188
      Top = 0
      Caption = 'Skini sve postere'
      ImageIndex = 2
      OnClick = ToolButtonSviPosteriClick
    end
  end
  object DBImage1: TDBImage
    Left = 864
    Top = 559
    Width = 382
    Height = 442
    DataField = 'poster'
    DataSource = DataSourceFilm
    Proportional = True
    Stretch = True
    TabOrder = 17
  end
  object Button1: TButton
    Left = 688
    Top = 510
    Width = 75
    Height = 25
    Caption = 'TEST DLL'
    TabOrder = 18
    OnClick = Button1Click
  end
  object XMLDocumentOmiljeniFilmovi: TXMLDocument
    FileName = 'C:\Users\Jan\Desktop\4sem\NTP\omiljeniFilmovi.xml'
    Left = 496
    Top = 120
  end
  object FDConnectionZaFilmove: TFDConnection
    Params.Strings = (
      'User_Name=root'
      'Database=iminidb'
      'Password=admin'
      'DriverID=MySQL')
    Connected = True
    LoginPrompt = False
    Left = 112
    Top = 640
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    VendorLib = 'C:\Users\Jan\Desktop\4sem\NTP\libmysql.dll'
    Left = 112
    Top = 704
  end
  object FDTableFilm: TFDTable
    Active = True
    IndexFieldNames = 'id'
    Connection = FDConnectionZaFilmove
    FetchOptions.AssignedValues = [evItems]
    ResourceOptions.AssignedValues = [rvEscapeExpand]
    TableName = 'iminidb.filmovi'
    Left = 112
    Top = 768
  end
  object DataSourceFilm: TDataSource
    DataSet = FDTableFilm
    Left = 112
    Top = 824
  end
  object FDQuerySelect: TFDQuery
    Active = True
    Connection = FDConnectionZaFilmove
    SQL.Strings = (
      
        'SELECT naslov,godina,trajanje,opis,zanr,redatelj,boxOffice,imdbR' +
        'ating,imdbVotes FROM Filmovi')
    Left = 288
    Top = 640
  end
  object FDQueryInsert: TFDQuery
    Connection = FDConnectionZaFilmove
    Left = 288
    Top = 704
  end
  object RESTClient1: TRESTClient
    Params = <>
    SynchronizedEvents = False
    Left = 440
    Top = 784
  end
  object RESTRequest1: TRESTRequest
    Client = RESTClient1
    Params = <>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 432
    Top = 632
  end
  object RESTResponse1: TRESTResponse
    Left = 440
    Top = 712
  end
  object FDQuerySortGodina: TFDQuery
    Active = True
    Connection = FDConnectionZaFilmove
    SQL.Strings = (
      
        'SELECT naslov,godina,trajanje,opis,zanr,redatelj,boxOffice,imdbR' +
        'ating,imdbVotes,poster'
      'FROM Filmovi'
      'WHERE godina IS NOT NULL'
      'ORDER BY godina DESC')
    Left = 288
    Top = 784
  end
  object FDQueryFilterOcjena: TFDQuery
    Connection = FDConnectionZaFilmove
    SQL.Strings = (
      
        'SELECT naslov,godina,imdbRating,trajanje,opis,zanr,redatelj,boxO' +
        'ffice,imdbVotes,poster '
      'FROM Filmovi'
      'where imdbRating >= 8'
      'order by imdbRating desc')
    Left = 288
    Top = 856
  end
  object FDQueryBrojFilmova: TFDQuery
    Active = True
    Connection = FDConnectionZaFilmove
    SQL.Strings = (
      'SELECT COUNT(naslov)'
      'FROM filmovi')
    Left = 288
    Top = 912
  end
  object SymetricCodec: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    Left = 584
    Top = 616
    StreamCipherId = ''
    BlockCipherId = ''
    ChainId = ''
  end
end
