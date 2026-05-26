object FormRecenzija: TFormRecenzija
  Left = 0
  Top = 0
  Caption = 'FormRecenzija'
  ClientHeight = 921
  ClientWidth = 1339
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object GroupBoxRecenzija: TGroupBox
    Left = 104
    Top = 8
    Width = 1041
    Height = 689
    TabOrder = 0
    object Label1: TLabel
      Left = 384
      Top = 273
      Width = 88
      Height = 15
      Caption = 'Datum recenzije:'
    end
    object Label2: TLabel
      Left = 435
      Top = 307
      Width = 26
      Height = 15
      Caption = 'Film:'
    end
    object Label4: TLabel
      Left = 328
      Top = 168
      Width = 40
      Height = 15
      Caption = 'Ocjena:'
    end
    object LabelOcjena: TLabel
      Left = 392
      Top = 200
      Width = 6
      Height = 15
      Caption = '1'
    end
    object LabelOcjena2: TLabel
      Left = 424
      Top = 200
      Width = 6
      Height = 15
      Caption = '2'
    end
    object LabelOcjena3: TLabel
      Left = 455
      Top = 200
      Width = 6
      Height = 15
      Caption = '3'
    end
    object LabelOcjena4: TLabel
      Left = 488
      Top = 200
      Width = 6
      Height = 15
      Caption = '4'
    end
    object LabelOcjena5: TLabel
      Left = 520
      Top = 200
      Width = 6
      Height = 15
      Caption = '5'
    end
    object LabelOcjena6: TLabel
      Left = 552
      Top = 200
      Width = 6
      Height = 15
      Caption = '6'
    end
    object LabelOcjena7: TLabel
      Left = 584
      Top = 200
      Width = 6
      Height = 15
      Caption = '7'
    end
    object LabelOcjena8: TLabel
      Left = 616
      Top = 200
      Width = 6
      Height = 15
      Caption = '8'
    end
    object LabelOcjena9: TLabel
      Left = 648
      Top = 200
      Width = 6
      Height = 15
      Caption = '9'
    end
    object LabelOcjena10: TLabel
      Left = 672
      Top = 200
      Width = 12
      Height = 15
      Caption = '10'
    end
    object ButtonSpremiRecenziju: TButton
      Left = 143
      Top = 528
      Width = 225
      Height = 94
      Caption = 'Spremi'
      TabOrder = 0
      OnClick = ButtonSpremiRecenzijuClick
    end
    object ButtonOdustani: TButton
      Left = 435
      Top = 528
      Width = 225
      Height = 94
      Caption = 'Odustani'
      TabOrder = 1
      OnClick = ButtonOdustaniClick
    end
    object memTekst: TMemo
      Left = 288
      Top = 365
      Width = 481
      Height = 97
      Lines.Strings = (
        'memTekst')
      TabOrder = 2
    end
    object dtpDatum: TDateTimePicker
      Left = 495
      Top = 265
      Width = 186
      Height = 23
      Date = 46109.000000000000000000
      Time = 0.531559131944959500
      TabOrder = 3
    end
    object edtFilm: TEdit
      Left = 495
      Top = 304
      Width = 186
      Height = 23
      TabOrder = 4
    end
    object TrackBarOcjena: TTrackBar
      Left = 384
      Top = 168
      Width = 310
      Height = 45
      Min = 1
      Position = 1
      TabOrder = 5
    end
    object ButtonPDF: TButton
      Left = 720
      Top = 528
      Width = 217
      Height = 94
      Caption = 'PDF'
      TabOrder = 6
      OnClick = ButtonPDFClick
    end
  end
  object cmbFilm: TComboBox
    Left = 563
    Top = 114
    Width = 145
    Height = 23
    TabOrder = 1
    OnChange = cmbFilmChange
  end
  object DBGridLookUpRecenzije: TDBGrid
    Left = 336
    Top = 703
    Width = 641
    Height = 185
    DataSource = DataSourceRecenzije
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object ButtonOscar: TButton
    Left = 1184
    Top = 32
    Width = 129
    Height = 49
    Caption = 'OSCAR'
    TabOrder = 3
    OnClick = ButtonOscarClick
  end
  object FDConnectionIMiniDB: TFDConnection
    Params.Strings = (
      'Database=iminidb'
      'User_Name=root'
      'Password=admin'
      'DriverID=MySQL')
    Connected = True
    LoginPrompt = False
    Left = 1208
    Top = 208
  end
  object FDQueryUnosRecenzije: TFDQuery
    Connection = FDConnectionIMiniDB
    Left = 8
    Top = 16
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    VendorLib = 'C:\Users\Jan\Desktop\4sem\NTP\libmysql.dll'
    Left = 1216
    Top = 272
  end
  object FDTableRecenzije: TFDTable
    Active = True
    IndexFieldNames = 'id'
    Connection = FDConnectionIMiniDB
    ResourceOptions.AssignedValues = [rvEscapeExpand]
    TableName = 'iminidb.recenzija'
    Left = 1168
    Top = 344
    object FDTableRecenzijeRecenzirao: TStringField
      DisplayWidth = 12
      FieldKind = fkLookup
      FieldName = 'Recenzirao'
      LookupDataSet = FDTableKorisnik
      LookupKeyFields = 'id'
      LookupResultField = 'korisnicko_ime'
      KeyFields = 'korisnik_id'
      Lookup = True
    end
    object FDTableRecenzijeid: TFDAutoIncField
      DisplayWidth = 2
      FieldName = 'id'
      Origin = 'id'
      ReadOnly = False
    end
    object FDTableRecenzijenaslov: TStringField
      DisplayWidth = 16
      FieldName = 'naslov'
      Origin = 'naslov'
      Required = True
      Size = 255
    end
    object FDTableRecenzijeStudentIme: TStringField
      DisplayWidth = 16
      FieldKind = fkLookup
      FieldName = 'StudentIme'
      LookupDataSet = FDTableKorisnik
      LookupKeyFields = 'id'
      LookupResultField = 'ime'
      KeyFields = 'korisnik_id'
      Visible = False
      Lookup = True
    end
    object FDTableRecenzijetekst: TMemoField
      AutoGenerateValue = arDefault
      DisplayWidth = 16
      FieldName = 'tekst'
      Origin = 'tekst'
      BlobType = ftMemo
    end
    object FDTableRecenzijeocjena: TIntegerField
      AutoGenerateValue = arDefault
      DisplayWidth = 16
      FieldName = 'ocjena'
      Origin = 'ocjena'
    end
    object FDTableRecenzijedatum: TDateTimeField
      AutoGenerateValue = arDefault
      DisplayWidth = 16
      FieldName = 'datum'
      Origin = 'datum'
    end
    object FDTableRecenzijekorisnik_id: TIntegerField
      AutoGenerateValue = arDefault
      DisplayWidth = 16
      FieldName = 'korisnik_id'
      Origin = 'korisnik_id'
    end
  end
  object FDTableKorisnik: TFDTable
    Active = True
    IndexFieldNames = 'id'
    Connection = FDConnectionIMiniDB
    ResourceOptions.AssignedValues = [rvEscapeExpand]
    TableName = 'iminidb.korisnik'
    Left = 1272
    Top = 344
  end
  object DataSourceRecenzije: TDataSource
    DataSet = FDTableRecenzije
    Left = 1176
    Top = 416
  end
  object DataSourceKorisnik: TDataSource
    DataSet = FDTableKorisnik
    Left = 1288
    Top = 424
  end
  object frxReport1: TfrxReport
    Version = '2024.1.2'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection, pbWatermarks]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 46131.500789675900000000
    ReportOptions.LastChange = 46168.851299282410000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'procedure MasterData1OnBeforePrint(Sender: TfrxComponent);'
      'begin'
      '  if MasterData1.RecNo mod 2 = 0 then'
      '    MasterData1.Color := $00F7F7F7'
      '  else'
      '    MasterData1.Color := $00FFFFFF;'
      'end;'
      ''
      'begin'
      ''
      'end.')
    Left = 1144
    Top = 704
    Datasets = <
      item
        DataSet = frxDBDatasetJOIN
        DataSetName = 'frxDBDatasetJOIN'
      end>
    Variables = <>
    Style = <>
    Watermarks = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 215.900000000000000000
      PaperHeight = 279.400000000000000000
      PaperSize = 1
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        Fill.BackColor = 1712832
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 74.000000000000000000
        Top = 18.897650000000000000
        Width = 740.409927000000000000
        object MemoLogoBox: TfrxMemoView
          AllowVectorExport = True
          Left = 10.000000000000000000
          Top = 15.000000000000000000
          Width = 115.000000000000000000
          Height = 44.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 1054880
          Font.Height = -8
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Fill.BackColor = 1054880
          ParentFont = False
        end
        object MemoLogoIMini: TfrxMemoView
          AllowVectorExport = True
          Left = 14.000000000000000000
          Top = 22.000000000000000000
          Width = 68.000000000000000000
          Height = 24.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGold
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Fill.BackColor = 1054880
          HAlign = haRight
          Memo.UTF8W = (
            'IMini')
          ParentFont = False
          VAlign = vaCenter
        end
        object MemoLogoDb: TfrxMemoView
          AllowVectorExport = True
          Left = 82.000000000000000000
          Top = 22.000000000000000000
          Width = 38.000000000000000000
          Height = 24.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Fill.BackColor = 1054880
          Memo.UTF8W = (
            'Db')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 140.000000000000000000
          Top = 16.000000000000000000
          Width = 450.000000000000000000
          Height = 22.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Fill.BackColor = 1712832
          Memo.UTF8W = (
            'Izvje'#353'taj korisni'#269'kih recenzija')
          ParentFont = False
          VAlign = vaCenter
        end
        object MemoDatum: TfrxMemoView
          AllowVectorExport = True
          Left = 140.000000000000000000
          Top = 42.000000000000000000
          Width = 450.000000000000000000
          Height = 14.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 11711154
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Fill.BackColor = 1712832
          Memo.UTF8W = (
            'Generirano: [FormatDateTime('#39'dd.mm.yyyy.'#39', Now)]')
          ParentFont = False
        end
        object MemoPageLabel: TfrxMemoView
          AllowVectorExport = True
          Left = 600.000000000000000000
          Top = 16.000000000000000000
          Width = 130.000000000000000000
          Height = 14.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 11711154
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Fill.BackColor = 1712832
          HAlign = haRight
          Memo.UTF8W = (
            'Stranica')
          ParentFont = False
        end
        object MemoPageNum: TfrxMemoView
          AllowVectorExport = True
          Left = 600.000000000000000000
          Top = 32.000000000000000000
          Width = 130.000000000000000000
          Height = 28.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -23
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Fill.BackColor = 1712832
          HAlign = haRight
          Memo.UTF8W = (
            '[Page#] / [TotalPages#]')
          ParentFont = False
        end
      end
      object PageHeader1: TfrxPageHeader
        FillType = ftBrush
        Fill.BackColor = 1712832
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 22.000000000000000000
        Top = 117.165430000000000000
        Width = 740.409927000000000000
        object MemoHNaslov: TfrxMemoView
          AllowVectorExport = True
          Left = 10.000000000000000000
          Top = 4.000000000000000000
          Width = 200.000000000000000000
          Height = 14.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 14145494
          Font.Height = -10
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Fill.BackColor = 1712832
          Memo.UTF8W = (
            'NASLOV FILMA')
          ParentFont = False
        end
        object MemoHOcjena: TfrxMemoView
          AllowVectorExport = True
          Left = 215.000000000000000000
          Top = 4.000000000000000000
          Width = 70.000000000000000000
          Height = 14.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 14145494
          Font.Height = -10
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Fill.BackColor = 1712832
          Memo.UTF8W = (
            'OCJENA')
          ParentFont = False
        end
        object MemoHDatum: TfrxMemoView
          AllowVectorExport = True
          Left = 290.000000000000000000
          Top = 4.000000000000000000
          Width = 100.000000000000000000
          Height = 14.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 14145494
          Font.Height = -10
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Fill.BackColor = 1712832
          Memo.UTF8W = (
            'DATUM')
          ParentFont = False
        end
        object MemoHRecenzija: TfrxMemoView
          AllowVectorExport = True
          Left = 395.000000000000000000
          Top = 4.000000000000000000
          Width = 340.944960000000000000
          Height = 14.000000000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 14145494
          Font.Height = -10
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Fill.BackColor = 1712832
          HAlign = haRight
          Memo.UTF8W = (
            'RECENZIJA')
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        Fill.BackColor = clWhite
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 76.000000000000000000
        Top = 200.315090000000000000
        Width = 740.409927000000000000
        OnBeforePrint = 'MasterData1OnBeforePrint'
        DataSet = frxDBDatasetJOIN
        DataSetName = 'frxDBDatasetJOIN'
        RowCount = 0
        object MemoNaslov: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 10.000000000000000000
          Top = 8.000000000000000000
          Width = 200.000000000000000000
          Height = 18.000000000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'naslov'
          DataSet = frxDBDatasetJOIN
          DataSetName = 'frxDBDatasetJOIN'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 2236962
          Font.Height = -14
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetJOIN."naslov"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object MemoOcjena: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 215.000000000000000000
          Top = 8.000000000000000000
          Width = 70.000000000000000000
          Height = 18.000000000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'ocjena'
          DataSet = frxDBDatasetJOIN
          DataSetName = 'frxDBDatasetJOIN'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 1712832
          Font.Height = -14
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetJOIN."ocjena"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object MemoRecDatum: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 290.000000000000000000
          Top = 8.000000000000000000
          Width = 100.000000000000000000
          Height = 18.000000000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'datum'
          DataSet = frxDBDatasetJOIN
          DataSetName = 'frxDBDatasetJOIN'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 5592405
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetJOIN."datum"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object MemoTekst: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 395.000000000000000000
          Top = 8.000000000000000000
          Width = 344.724490000000000000
          Height = 18.000000000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'tekst'
          DataSet = frxDBDatasetJOIN
          DataSetName = 'frxDBDatasetJOIN'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 5592405
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            '[frxDBDatasetJOIN."tekst"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object MemoRecenziraoLabel: TfrxMemoView
          AllowVectorExport = True
          Left = 10.000000000000000000
          Top = 44.000000000000000000
          Width = 80.000000000000000000
          Height = 16.000000000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 8947848
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsItalic]
          Frame.Typ = []
          Memo.UTF8W = (
            'Recenzirao:')
          ParentFont = False
          VAlign = vaCenter
        end
        object LineBottom: TfrxLineView
          AllowVectorExport = True
          Top = 75.000000000000000000
          Width = 740.409927000000000000
          Color = 15000804
          Frame.Typ = [ftTop]
        end
        object MemofrxDBDatasetJOINkorisnicko_ime: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 83.149660000000000000
          Top = 45.354360000000000000
          Width = 377.953000000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'korisnicko_ime'
          DataSet = frxDBDatasetJOIN
          DataSetName = 'frxDBDatasetJOIN'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetJOIN."korisnicko_ime"]')
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        FillType = ftBrush
        Fill.BackColor = 1710618
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 28.000000000000000000
        Top = 336.378170000000000000
        Width = 740.409927000000000000
        object MemoFooterL: TfrxMemoView
          AllowVectorExport = True
          Left = 10.000000000000000000
          Top = 6.000000000000000000
          Width = 420.000000000000000000
          Height = 16.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 6710886
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Fill.BackColor = 1710618
          Memo.UTF8W = (
            #169' 2026 IMiniDb '#8212' Sustav za recenziranje filmova')
          ParentFont = False
          VAlign = vaCenter
        end
        object MemoFooterR: TfrxMemoView
          AllowVectorExport = True
          Left = 500.000000000000000000
          Top = 6.000000000000000000
          Width = 230.000000000000000000
          Height = 16.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 1712832
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Fill.BackColor = 1710618
          HAlign = haRight
          Memo.UTF8W = (
            #9733#9733#9733#9733#9733)
          ParentFont = False
          VAlign = vaCenter
        end
      end
    end
  end
  object PReport1: TPReport
    FileName = 'default.pdf'
    CreationDate = 46133.710194768520000000
    UseOutlines = False
    ViewerPreference = []
    Left = 1160
    Top = 800
  end
  object frxDBDatasetRecenzije: TfrxDBDataset
    UserName = 'frxDBDatasetRecenzije'
    CloseDataSource = False
    DataSet = FDTableRecenzije
    BCDToCurrency = False
    DataSetOptions = []
    Left = 1072
    Top = 776
    FieldDefs = <
      item
        FieldName = 'Recenzirao'
        FieldType = fftString
        Size = 20
      end
      item
        FieldName = 'id'
      end
      item
        FieldName = 'naslov'
        FieldType = fftString
        Size = 255
      end
      item
        FieldName = 'StudentIme'
        FieldType = fftString
        Size = 20
      end
      item
        FieldName = 'tekst'
        FieldType = fftString
      end
      item
        FieldName = 'ocjena'
      end
      item
        FieldName = 'datum'
        FieldType = fftDateTime
      end
      item
        FieldName = 'korisnik_id'
      end>
  end
  object frxDBDatasetKorisnik: TfrxDBDataset
    UserName = 'frxDBDatasetKorisnik'
    CloseDataSource = False
    DataSet = FDTableKorisnik
    BCDToCurrency = False
    DataSetOptions = []
    Left = 1232
    Top = 744
    FieldDefs = <
      item
        FieldName = 'id'
      end
      item
        FieldName = 'ime'
        FieldType = fftString
        Size = 100
      end
      item
        FieldName = 'prezime'
        FieldType = fftString
        Size = 100
      end
      item
        FieldName = 'korisnicko_ime'
        FieldType = fftString
        Size = 100
      end
      item
        FieldName = 'email'
        FieldType = fftString
        Size = 150
      end
      item
        FieldName = 'lozinka_hash'
        FieldType = fftString
        Size = 255
      end>
  end
  object Codec1: TCodec
    AsymetricKeySizeInBits = 0
    AdvancedOptions2 = []
    Left = 136
    Top = 768
    StreamCipherId = ''
    BlockCipherId = ''
    ChainId = ''
  end
  object frxPDFExport1: TfrxPDFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    InteractiveFormsFontSubset = 'A-Z,a-z,0-9,#43-#47 '
    OpenAfterExport = False
    PrintOptimized = False
    Outline = False
    Background = False
    Quality = 95
    Author = 'FastReport'
    Subject = 'FastReport PDF export'
    Creator = 'FastReport'
    ProtectionFlags = [ePrint, eModify, eCopy, eAnnot]
    HideToolbar = False
    HideMenubar = False
    HideWindowUI = False
    FitWindow = False
    CenterWindow = False
    PrintScaling = False
    PdfA = False
    PDFStandard = psNone
    PDFVersion = pv17
    PDFColorSpace = csDeviceRGB
    Left = 1072
    Top = 848
  end
  object FDQueryBrojKorisnika: TFDQuery
    MasterSource = DataSourceKorisnik
    Connection = FDConnectionIMiniDB
    Left = 1176
    Top = 568
  end
  object frxDBDatasetJOIN: TfrxDBDataset
    UserName = 'frxDBDatasetJOIN'
    CloseDataSource = False
    DataSet = FDQueryJOIN
    BCDToCurrency = False
    DataSetOptions = []
    Left = 1224
    Top = 840
    FieldDefs = <
      item
        FieldName = 'id'
      end
      item
        FieldName = 'naslov'
        FieldType = fftString
        Size = 255
      end
      item
        FieldName = 'tekst'
        FieldType = fftString
      end
      item
        FieldName = 'ocjena'
      end
      item
        FieldName = 'datum'
        FieldType = fftDateTime
      end
      item
        FieldName = 'korisnik_id'
      end
      item
        FieldName = 'film_id'
      end
      item
        FieldName = 'id_1'
      end
      item
        FieldName = 'ime'
        FieldType = fftString
        Size = 100
      end
      item
        FieldName = 'prezime'
        FieldType = fftString
        Size = 100
      end
      item
        FieldName = 'korisnicko_ime'
        FieldType = fftString
        Size = 100
      end
      item
        FieldName = 'email'
        FieldType = fftString
        Size = 150
      end
      item
        FieldName = 'lozinka_hash'
        FieldType = fftString
        Size = 255
      end>
  end
  object FDQueryJOIN: TFDQuery
    Active = True
    Connection = FDConnectionIMiniDB
    SQL.Strings = (
      'SELECT * FROM recenzija'
      'inner join korisnik on korisnik.id = recenzija.korisnik_id')
    Left = 1224
    Top = 696
  end
end
