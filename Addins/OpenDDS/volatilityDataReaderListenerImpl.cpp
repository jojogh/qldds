/*
   Copyright (C) 2013 Mike Kipnis

   This file is part of QLDDS, a free-software/open-source library
   for utilization of QuantLib in the distributed envrionment via DDS.

   QLDDS is free software: you can redistribute it and/or modify it
   under the terms of the QLDDS license.  You should have received a
   copy of the license along with this program; if not, please email
   <dev@qldds.org>. The license is also available online at
   <http://qldds.org/qldds-license/>.

   This program is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the license for more details.
*/
// This file was generated automatically by qldds_gensrc.py.  If you edit this file
// manually then your changes will be lost the next time gensrc runs.

// This source code file was generated from the following stub:
//      Users/mkipnis/Dev/qldds/gensrc/stubs/stub.opendds.body

#include "volatilityDataReaderListenerImpl.hpp"

#include <qldds_convert_utils.h>

namespace volatility {

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   volatility::qlMarketModelLmExtLinearExponentialVolModelDataReader_var obj_dr
     = volatility::qlMarketModelLmExtLinearExponentialVolModelDataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    volatility::qlMarketModelLmExtLinearExponentialVolModel obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlMarketModelLmExtLinearExponentialVolModel ( 
              obj.ObjectId.in(),
             qldds_utils::vector_cast<double,CORBA::DoubleSeq>(obj.FixingTimes),
              static_cast<double>(obj.A),
              static_cast<double>(obj.B),
              static_cast<double>(obj.C),
              static_cast<double>(obj.D),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlMarketModelLmExtLinearExponentialVolModel: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_subscription_matched\n")));
}

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_reading_start\n")));
}

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, volatility::qlMarketModelLmExtLinearExponentialVolModel& )
{
  return true;
}

bool qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, volatility::qlMarketModelLmExtLinearExponentialVolModel&, std::string& )
{
  return true;
}

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, volatility::qlMarketModelLmExtLinearExponentialVolModel&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlMarketModelLmExtLinearExponentialVolModelDataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   volatility::qlPiecewiseConstantAbcdVarianceDataReader_var obj_dr
     = volatility::qlPiecewiseConstantAbcdVarianceDataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    volatility::qlPiecewiseConstantAbcdVariance obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlPiecewiseConstantAbcdVariance ( 
              obj.ObjectId.in(),
              static_cast<double>(obj.A),
              static_cast<double>(obj.B),
              static_cast<double>(obj.C),
              static_cast<double>(obj.D),
              static_cast<long>(obj.ResetIndex),
             qldds_utils::vector_cast<double,CORBA::DoubleSeq>(obj.RateTimes),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlPiecewiseConstantAbcdVariance: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_subscription_matched\n")));
}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_reading_start\n")));
}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, volatility::qlPiecewiseConstantAbcdVariance& )
{
  return true;
}

bool qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, volatility::qlPiecewiseConstantAbcdVariance&, std::string& )
{
  return true;
}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, volatility::qlPiecewiseConstantAbcdVariance&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPiecewiseConstantAbcdVarianceDataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}
}
